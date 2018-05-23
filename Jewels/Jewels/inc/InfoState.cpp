#include "InfoState.hpp"

InfoState::InfoState(sf::RenderWindow& _window) {
	game_bg.SetImage("game_bg1");
	text = new Text("Author: Volodymyr Shevchenko, 2018", 25);
	text->SetPosition(sf::Vector2f(_window.getSize().x / 2.0f - text->GetRect().width / 2.0f,
		_window.getSize().y / 2.0f - text->GetRect().height / 2.0f));
}

void InfoState::Update(sf::RenderWindow& window, float _time)  {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		main_state.SwitchState(STATE::MENU);
	}
}

void InfoState::Draw(sf::RenderWindow& window) {
	text->Draw(window);
}

void InfoState::Destroy() {
	delete text;
}