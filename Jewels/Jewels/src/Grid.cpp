#include "..\inc\Grid.hpp"

Grid::Grid(const sf::RenderWindow& window) {
	cols = rows = GRID_SIZE;

	size = new sf::Vector2f;
	*size = sf::Vector2f(this->cols * BOX_SIZE, this->rows * BOX_SIZE);
	
	position = new sf::Vector2f;
	*position = sf::Vector2f((window.getSize().x - size->x) / 2.0f,
		(window.getSize().y - size->y) / 2.0f);

	for (int i = 0; i < GRID_SIZE; ++i) {
		cells.push_back(std::vector<OpenBox>(GRID_SIZE));
		for (int j = 0; j < GRID_SIZE; ++j) {
			cells[i][j].SetPosition(position->x + j * (BOX_SIZE + BOX_BORDER),
				position->y + i * (BOX_SIZE + BOX_BORDER));
		}
	}

	bound = new Box;
	bound->SetTexture(resMng->textures.Get("select"));
	bound->SetColor(sf::Color(166, 239, 255));

	showBound = false;
	srand(static_cast<unsigned int>(time(NULL)));

	markedBox = new sf::Vector2i;
	movedBox = new sf::Vector2i;
}

Grid::~Grid() {
	delete position;
	delete size;
	delete markedBox;
	delete movedBox;
}

void Grid::Generate() {
	int items[BOX_TYPES] = { 0 };
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			unsigned short value;
			do {
				value = 1 + rand() % BOX_TYPES;
			} while (items[value - 1] >= ceil(pow(GRID_SIZE, 2) / BOX_TYPES));
			items[value - 1]++;
			cells[i][j].SetValue(value);
		}
	}
}

int Grid::RandomValue(int v1, int v2) {
	unsigned short value;
	do {
		value = 1 + rand() % BOX_TYPES;
	} while (value == v1 || value == v2);
	return value;
}

void Grid::DeleteCopies() {
	int new_value, prev_value;
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 1; j < GRID_SIZE - 1; ++j) {
			new_value = prev_value = 0;
			if (cells[i][j] == cells[i][j - 1] && cells[i][j] == cells[i][j + 1]) {
				new_value = this->RandomValue(cells[i][j].GetValue());
				prev_value = cells[i][j].GetValue();
				cells[i][j].SetValue(new_value);
			}

			if (cells[j][i] == cells[j - 1][i] && cells[j][i] == cells[j + 1][i]) {
				new_value = this->RandomValue(cells[j][i].GetValue(), prev_value);
				prev_value = cells[j][i].GetValue();
				cells[j][i].SetValue(new_value);
			}

		}
	}
}


bool Grid::FindingMatch(int i, int j) {
	bool x_axis = false, y_axis;
	int m_j = markedBox->x, m_i = markedBox->y;

	this->SwapValues(cells[i][j], cells[m_i][m_j]);
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 1; j < GRID_SIZE - 1; ++j) {
			if (cells[i][j] == cells[i][j - 1] && cells[i][j] == cells[i][j + 1]) {
				for (int k = -1; k <= 1; ++k) {
					cells[i][j + k].SetMatch(true);
				}
				x_axis = true;
			}
			if (cells[j][i] == cells[j - 1][i] && cells[j][i] == cells[j + 1][i]) {
				for (int k = -1; k <= 1; ++k) {
					cells[j + k][i].SetMatch(true);
				}
				y_axis = true;
			}
		}
	}
	this->SwapValues(cells[i][j], cells[m_i][m_j]);
	
	return x_axis || y_axis;
}


void Grid::Update(sf::RenderWindow& window, float _time) {
	int m_j = markedBox->x;
	int m_i = markedBox->y;

	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			cells[i][j].Update(window, _time);
			
			if(cells[i][j].isClicked(window) && !cells[i][j].inMotion()) { 
				if(this->AllowedMove(j, i) && showBound) {
					DIRECTION direct = IdentifyDirection(j, i);
					m_j = markedBox->x;
					m_i = markedBox->y;

					cells[i][j].Slide(direct);
					cells[m_i][m_j].Slide((DIRECTION)-direct);
					
					if (this->FindingMatch(i, j)) {
						cells[i][j].SetSwapState(true);
						cells[m_i][m_j].SetSwapState(true);
					}
					*movedBox = sf::Vector2i(j, i);
					showBound = false;
				}
				else {
					bound->SetPosition(cells[i][j].GetPosition());
					*markedBox = sf::Vector2i(j, i);
					showBound = true;
				}
				
			}
			
		}
	}

	int mvd_i = movedBox->y;
	int mvd_j = movedBox->x;

	if (cells[mvd_i][mvd_j].GetMoved() && cells[m_i][m_j].GetMoved()
		&& !cells[mvd_i][mvd_j].inMotion() && !cells[m_i][m_j].inMotion()) {

		if (cells[mvd_i][mvd_j].GetSwapState() && cells[m_i][m_j].GetSwapState()) {
			this->SwapCells(cells[mvd_i][mvd_j], cells[m_i][m_j]);
		}
		else {
			DIRECTION dir = IdentifyDirection(mvd_j, mvd_i);
			cells[mvd_i][mvd_j].Slide((DIRECTION)-dir);
			cells[m_i][m_j].Slide(dir);
		}
	}
	
}

void Grid::Draw(sf::RenderWindow& window) {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			cells[i][j].Draw(window);
		}
	}
	if(showBound)
		bound->Draw(window);
}

bool Grid::AllowedMove(int x, int y) {
	int dx, dy;
	dx = std::abs(x - markedBox->x);
	dy = std::abs(y - markedBox->y);

	return (!dx && dy == 1 || !dy && dx == 1);
}

DIRECTION Grid::IdentifyDirection(int x, int y) {
	DIRECTION dir = NONE;

	if (y == markedBox->y) {
		if (x > markedBox->x) {
			dir = LEFT;
		}
		else {
			dir = RIGHT;
		}
	}
	else if (x == markedBox->x) {
		if (y > markedBox->y) {
			dir = UP;
		}
		else {
			dir = DOWN;
		}
	}
	
	return dir;
}

void Grid::SwapCells(OpenBox& first, OpenBox& second) {
	int value1 = first.GetValue();
	int value2 = second.GetValue();
	std::cout << "#swap" << std::endl;

	sf::Sprite s1 = first.GetSprite();
	sf::Sprite s2 = second.GetSprite();
	first.SetSprite(s2);
	first.SetValue(value2);
	first.SetSwapState(false);
	first.SetMoved(false);

	second.SetSprite(s1);
	second.SetValue(value1);
	second.SetSwapState(false);
	second.SetMoved(false);
}

void Grid::SwapValues(OpenBox& first, OpenBox& second) {
	int value1 = first.GetValue();
	int value2 = second.GetValue();

	first.SetValue(value2);
	second.SetValue(value1);
}