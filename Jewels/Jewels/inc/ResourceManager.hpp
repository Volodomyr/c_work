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
	Resource<sf::Texture> textures; //контейнер для текстур
	Resource<sf::SoundBuffer> sounds; //контейнер для звуков
	Resource<sf::Font> fonts; //контейнер для шрифтов

	static ResourceManager* get();
};

#define resMngr	ResourceManager::get()
#endif //RESOURCE_MANAGER_H