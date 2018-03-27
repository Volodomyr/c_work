#include "..\inc\MenuState.hpp"
#include "..\inc\Game.hpp"

void nop() {
	std::cout << "$" << std::endl;
}

MenuState::MenuState(sf::RenderWindow& window) {
	std::string titleArr[] = { "PLAY", "OPTIONS", "ACHIEVEMENTS", "INFO", "QUIT" };
	Button temp[BTN_COUNT];
	menu_panel = new sf::RectangleShape();
	menu_panel->setFillColor(sf::Color(150, 150, 150, 0));

	size.x = 2 * OFFSET + temp[NULL].getSize().x;
	size.y = OFFSET + BTN_COUNT * (BTN_SPACE + temp[NULL].getSize().y);
	menu_panel->setSize(size);

	pos = sf::Vector2f((window.getSize().x - this->size.x) / 2.0f,
		(window.getSize().y - this->size.y) / 2.0f + 0.07f * window.getSize().y);
	menu_panel->setPosition(pos);


	background = new sf::RectangleShape();
	background->setSize(sf::Vector2f(window.getSize().x, window.getSize().y));
	background->setTexture(&resMngr->textures.Get("menu_bg"));

	for (int i = 0; i < BTN_COUNT; ++i) {
		temp[i].SetText(titleArr[i]);
		temp[i].SetTexture(resMngr->textures.Get("menu_btn"));

		float x_pos = pos.x + OFFSET;
		float y_pos = pos.y + OFFSET + i * (BTN_SPACE + temp[0].getSize().y);

		temp[i].SetPosition(x_pos, y_pos);
		temp[i].SetFunction(nop);
	}

	temp[0].SetFunction([this]() { //define func for button 'Play'
		main_state.SwitchState(STATE::PLAY);
	});
	temp[4].SetFunction([this]() { //define func for button 'Exit'
		main_state.SwitchState(STATE::CLOSE);
	});

	//////////////////////
	for (int i = 0; i < BTN_COUNT; ++i) {
		items.push_back(temp[i]);
	}
}


void MenuState::Update(sf::Event e, sf::RenderWindow& window, float time) {
	for (auto &it : items) {
		it.HandleEvent(e, window);
	}
}

void MenuState::Destroy() {
	delete menu_panel;
	delete background;
}

void MenuState::Draw(sf::RenderWindow& window) {
	window.draw(*this->background);
	window.draw(*this->menu_panel);
	for (auto &it = items.begin(); it != items.end(); it++) {
		it->Draw(window);
	}
}

void MenuState::SetPos(float x, float y) {
	pos = sf::Vector2f(x, y);
	menu_panel->setPosition(pos);
}

void MenuState::SetSize(const sf::Vector2f& _size) {
	size = _size;
	menu_panel->setSize(size);
}
