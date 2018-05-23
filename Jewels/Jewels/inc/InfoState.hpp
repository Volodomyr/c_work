#pragma once
#ifndef INFO_STATE_H
#define INFO_STATE_H
#include "State.hpp"
#include <SFML\Graphics.hpp>
#include "Background.hpp"
#include "Text.hpp"
#include "StateControl.hpp"

class InfoState : public State {
	Text *text;

public:
	InfoState(sf::RenderWindow& _window);
	~InfoState() { this->Destroy(); }
	void Update(sf::RenderWindow& window, float _time) override;
	void Draw(sf::RenderWindow& window) override;
	void Destroy() override;
};

#endif //INFO_STATE_H