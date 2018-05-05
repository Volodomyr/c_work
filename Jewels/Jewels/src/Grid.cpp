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
	bound->SetTexture(resMng->getTexture("select"));
	bound->SetColor(sf::Color(166, 239, 255));

	showBound = false;
	srand(static_cast<unsigned int>(time(NULL)));

	markedBox = new sf::Vector2i;
	movedBox = new sf::Vector2i;
	sound = new sf::Sound;
	state =  GRID_STATE::NUL;
}

Grid::~Grid() {
	delete position;
	delete size;
	delete markedBox;
	delete movedBox;
	delete sound;
}

void Grid::Generate() {
	int items[BOX_TYPES] = { 0 };
	const int MAX_BOX_TYPES = ceil(pow(GRID_SIZE, 2) / BOX_TYPES);
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			unsigned short value;
			do {
				value = 1 + rand() % BOX_TYPES;
			} while (items[value - 1] >= MAX_BOX_TYPES);
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


void Grid::FindingMatch() {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE - 2; ++j) {
			if (cells[i][j] == cells[i][j + 1] && cells[i][j] == cells[i][j + 2]) { //îñü ÎÕ
				cells[i][j].SetMatch(true);

				for (int k = j + 1; k < GRID_SIZE; ++k) {
					if (cells[i][k] == cells[i][k - 1]) {
						cells[i][k].SetMatch(true);
					}
					else break;
				}
			}
			if (cells[j][i] == cells[j + 1][i] && cells[j][i] == cells[j + 2][i]) {//îñü ÎÓ
				cells[j][i].SetMatch(true);

				for (int k = j + 1; k < GRID_SIZE; ++k) {
					if (cells[k][i] == cells[k - 1][i]) {
						cells[k][i].SetMatch(true);
					}
					else break;
				}
			}
		}
	}
}

bool Grid::ConsistMatchInLine(int i, int j) {
	bool x_axis = false, y_axis = false;
	int m_j = markedBox->x, m_i = markedBox->y;

	this->SwapValues(cells[i][j], cells[m_i][m_j]);

	for (int t = 0; t < GRID_SIZE - 2; ++t) {
		if (cells[i][t] == cells[i][t + 1] && cells[i][t] == cells[i][t + 2]
			|| cells[m_i][t] == cells[m_i][t + 1] && cells[m_i][t] == cells[m_i][t + 2]) {
			x_axis = true;
			break;
		}
		if (cells[t][j] == cells[t + 1][j] && cells[t][j] == cells[t + 2][j]
			|| cells[t][m_j] == cells[t + 1][m_j] && cells[t][m_j] == cells[t + 2][m_j]) {
			y_axis = true;
			break;
		}
	}
	this->SwapValues(cells[i][j], cells[m_i][m_j]);

	return x_axis || y_axis;
}

void Grid::Update(sf::RenderWindow& window, float _time) {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			cells[i][j].Update(window, _time);
			
			if(cells[i][j].isClicked(window) && !cells[i][j].inMotion()) { 
				if(this->AllowedMove(j, i) && showBound) {
					DIRECTION direct = IdentifyDirection(j, i);
					int m_j = markedBox->x;
					int m_i = markedBox->y;

					cells[i][j].Slide(direct);
					cells[m_i][m_j].Slide((DIRECTION)-direct);
					
					if (this->ConsistMatchInLine(i, j)) {
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
					sound->setBuffer(resMng->getSound("cursor_activate"));
					sound->play();
				}
			}
			
		}
	}

	state = this->StateProcessing(state);
}

GRID_STATE Grid::StateProcessing(GRID_STATE _state) {
	int mvd_i = movedBox->y;
	int mvd_j = movedBox->x;
	int m_j = markedBox->x;
	int m_i = markedBox->y;

	if (cells[mvd_i][mvd_j].GetMoved() && cells[m_i][m_j].GetMoved()
		&& !cells[mvd_i][mvd_j].inMotion() && !cells[m_i][m_j].inMotion()) {

		if (cells[mvd_i][mvd_j].GetSwapState() && cells[m_i][m_j].GetSwapState()) {
			_state = GRID_STATE::SWAP;
		}
		else {
			DIRECTION dir = IdentifyDirection(mvd_j, mvd_i);
			cells[mvd_i][mvd_j].Slide((DIRECTION)-dir);
			cells[m_i][m_j].Slide(dir);
		}
	}

	switch (_state) {
		case SWAP:
			this->SwapCells(cells[mvd_i][mvd_j], cells[m_i][m_j]);
			_state = GRID_STATE::FIND_MATCH;
			break;
		case FIND_MATCH:
			this->FindingMatch();
			_state = GRID_STATE::SHIFT_LINES;
			break;
		case SHIFT_LINES:
			this->ShiftLines();
			_state = GRID_STATE::FIND_MATCH;
			break;
	}
	return _state;
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
	DIRECTION dir = DIRECTION::NONE;

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

void Grid::ShiftLines() {
	for (int i = GRID_SIZE - 1; i > 0; --i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			if (!cells[i][j].isFill() && !cells[i][j].isAnimPlaying()) {
				cells[i][j].SetMatch(false);
				this->SwapValues(cells[i][j], cells[i - 1][j]);
			}
		}
	}

	for (int i = 0; i < GRID_SIZE; ++i) {
		if (!cells[0][i].isFill() && !cells[0][i].isAnimPlaying()) {
			cells[0][i].SetMatch(false);
			int value = 0;
			do {
				value = this->RandomValue(0);
				if (i && value == cells[0][i - 1].GetValue()
					|| i < GRID_SIZE - 1 && value == cells[0][i + 1].GetValue()) {
					continue;
				}
			} while (value == cells[1][i].GetValue());
			
			cells[0][i].SetValue(value);
		}
	}
}

bool Grid::ConsistMatch(Matrix& _cells) {
	bool result = false;
	
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE - 2; ++j) {
			if (_cells[i][j] == _cells[i][j + 1] && _cells[i][j] == _cells[i][j + 2]) {
				result = true;
				break;
			}
			if (_cells[j][i] == _cells[j + 1][i] && _cells[j][i] == _cells[j + 2][i]) {
				result = true;
				break;
			}
		}
	}
	return result;
}

bool Grid::isCorrectIndex(size_t index, size_t max) {
	return index >= 0 && index < max;
}

void Grid::CellDistribute() {
	std::vector<int> list;

	for (size_t i = 0; i < cells.size(); ++i) {
		for (size_t j = 0; j < cells[0].size(); ++j) {
			list.push_back(cells[i][j].GetValue());
		}
	}

	while (ConsistMatch(cells)) {
		std::random_shuffle(list.begin(), list.end());

		for (size_t i = 0; i < cells.size(); ++i) {
			for (size_t j = 0; j < cells[0].size(); ++j) {
				cells[i][j].SetValue(list[i * cells[0].size() + j]);
			}
		}
	}
}