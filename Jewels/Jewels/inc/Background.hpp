#pragma once
#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML\Graphics.hpp>
#include <string>
#include "ResourceManager.hpp"

class Background {
	sf::Sprite *rect;

public:
	Background();
	~Background();
	void SetImage(const std::string& imageName);
	void Draw(sf::RenderWindow& window);
};

extern Background game_bg;
#endif //BACKGROUND_H