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
