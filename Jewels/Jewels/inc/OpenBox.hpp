#pragma once
#ifndef OPEN_BOX_H
#define OPEN_BOX_H
#include "Box.hpp"

/*
class OpenBox : public Box {
	sf::Texture *texture;

public:
	OpenBox(): Box() {
		texture = new sf::Texture();
		
	}

	void SetPosition(float x, float y) override {
		*position = sf::Vector2f(x, y);
		rect->setPosition(*position);
	}

	void Update(sf::Event e, float time) override {

	}

	void Draw(sf::RenderWindow& window) override {
		window.draw(*rect);
	}
	~OpenBox() {
		delete texture;
	}


};

*/

#endif //OPEN_BOX_H