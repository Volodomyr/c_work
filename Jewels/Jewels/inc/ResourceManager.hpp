#pragma once
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Resource.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

class ResourceManager {
private:
	ResourceManager();
	Resource<sf::Texture> textures; //��������� ��� �������
	Resource<sf::SoundBuffer> sounds; //��������� ��� ������
	Resource<sf::Font> fonts; //��������� ��� �������

public:
	sf::Texture& getTexture(const std::string& textureName);
	sf::SoundBuffer& getSound(const std::string& soundName);
	sf::Font& getFont(const std::string& fontName);

	static ResourceManager* get();
};

#define resMng	ResourceManager::get()
#endif //RESOURCE_MANAGER_H