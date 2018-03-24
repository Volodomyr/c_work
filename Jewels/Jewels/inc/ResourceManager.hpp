#pragma once
#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "Resource.hpp"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"

class ResourceManager {
private:
	ResourceManager();

public:
	Resource<sf::Texture> textures; //��������� ��� �������
	Resource<sf::SoundBuffer> sounds; //��������� ��� ������
	Resource<sf::Font> fonts; //��������� ��� �������

	static ResourceManager* get();
};

#define resMngr	ResourceManager::get()
#endif //RESOURCE_MANAGER_H