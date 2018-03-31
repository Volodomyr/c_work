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
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			unsigned short value = 1 + rand() % BOX_TYPES;
			cells[i][j].SetValue(value);
		}
	}
}

void Grid::Update(sf::RenderWindow& window, float _time) {
	for (int i = 0; i < GRID_SIZE; ++i) {
		for (int j = 0; j < GRID_SIZE; ++j) {
			cells[i][j].Update(window, _time);
			
			if(cells[i][j].isClicked(window) && !cells[i][j].inMotion()) { 
				if(this->AllowedMove(j, i) && showBound) {
					DIRECTION direct = IdentifyDirection(j, i);
					int m_X = markedBox->x;
					int m_Y = markedBox->y;

					cells[i][j].SetDirection(direct);
					//cells[i][j].SetAlphaLevel(-100, 255);
					cells[m_Y][m_X].SetDirection((DIRECTION)-direct);
					//cells[m_Y][m_X].SetAlphaLevel(-100, 255);
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

	if (cells[movedBox->y][movedBox->x].GetSwapState() && 
		cells[markedBox->y][markedBox->x].GetSwapState()) {
		this->SwapCells(cells[movedBox->y][movedBox->x], cells[markedBox->y][markedBox->x]);
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
	/*int value1 = first.GetValue();
	int value2 = second.GetValue();

	first.BackToOrigin();
	first.SetValue(value2);
	first.SetSwapState(false);
	//first.SetAlphaLevel(110, 0);

	second.BackToOrigin();
	second.SetValue(value1);
	second.SetSwapState(false);
	//second.SetAlphaLevel(110, 0);*/

	sf::Sprite *s1 = first.GetSprite();
	sf::Sprite *s2 = second.GetSprite();
	first.SetSprite(*s2);
	first.SetSwapState(false);

	second.SetSprite(*s1);
	second.SetSwapState(false);


}