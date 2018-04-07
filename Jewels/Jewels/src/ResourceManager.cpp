#include "..\inc\ResourceManager.hpp"

ResourceManager::ResourceManager() :
	textures("textures", "png"),
	sounds("sounds", "ogg"),
	fonts("fonts", "ttf") //ttf
{
}

ResourceManager* ResourceManager::get() {
	static ResourceManager res_mng;
	return &res_mng;
}

sf::Texture& ResourceManager::getTexture(const std::string& textureName) {
	return textures.Get(textureName);
}

sf::SoundBuffer& ResourceManager::getSound(const std::string& soundName) {
	return sounds.Get(soundName);
}

sf::Font& ResourceManager::getFont(const std::string& fontName) {
	return fonts.Get(fontName);
}
