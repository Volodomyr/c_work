#include "..\inc\MenuState.hpp"
#include "..\inc\Game.hpp"
#include <iostream>

void nop() {
	std::cout << "#" << std::endl;
}

MenuState::MenuState(Game* _game) {
	std::string titleArr[] = { "Start", "Options", "Achievements", "Information", "Exit" };
	Button temp[BTN_COUNT];
	game = _game;

	background.setFillColor(sf::Color(150, 150, 150));
	background.setOutlineColor(sf::Color::Blue);
	sf::RenderWindow *window = game->GetWindow();

	size.x = 2 * OFFSET + temp[NULL].getSize().x;
	size.y = OFFSET + BTN_COUNT * (BTN_SPACE + temp[NULL].getSize().y);
	background.setSize(size);

	pos = sf::Vector2f((window->getSize().x - this->size.x)/ 2.0f, 
					     (window->getSize().y - this->size.y) / 2.0f);
	background.setPosition(pos);

	for (int i = 0; i < BTN_COUNT; ++i) {
		temp[i].SetText(titleArr[i]);
		temp[i].SetTexture(resMngr->textures.Get("btn"));


		float x_pos = pos.x + OFFSET;
		float y_pos = pos.y + OFFSET + i * (BTN_SPACE + temp[0].getSize().y);

		temp[i].SetPosition(x_pos, y_pos);
		temp[i].SetFunction(nop);

	}



	//////////////////////
	for (int i = 0; i < BTN_COUNT; ++i) {
		items.push_back(temp[i]);
	}

}


void MenuState::Update(sf::Event e, const sf::RenderWindow& _window) {
	//while (game->gameState == Game::MENU) {
	for (auto &it = items.begin(); it != items.end(); it++) {
		it->HandleEvent(e, _window);
	}

	//}
}

void MenuState::SetPos(float x, float y) {
	pos = sf::Vector2f(x, y);
	background.setPosition(pos);
}

void MenuState::SetSize(const sf::Vector2f& _size) {
	size = _size;
	background.setSize(size);
}

void MenuState::Draw(sf::RenderTarget& _window) {
	_window.draw(this->background);
	for (auto &it = items.begin(); it != items.end(); it++) {
		it->Draw(_window);
	}
}