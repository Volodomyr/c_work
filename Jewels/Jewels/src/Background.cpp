#include "..\inc\Background.hpp"

Background::Background() {
	rect = new sf::Sprite;
	rect->setColor(sf::Color::White);
}

Background::~Background() {
	delete rect;
}

void Background::SetImage(const std::string& imageName) {
	rect->setTexture(resMng->textures.Get(imageName));
}

void Background::Draw(sf::RenderWindow& window) {
	window.draw(*rect);
}

