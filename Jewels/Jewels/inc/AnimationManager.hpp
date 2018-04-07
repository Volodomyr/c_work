#pragma once
#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H
#include <unordered_map>
#include <string>
#include "Animation.hpp"
#include "..\tinyxml\tinyxml.h"
const float ANIMATION_SPEED = 1000.f;

class AnimationManager {
	std::unordered_map<std::string, Animation> m_animations;
	const std::string folder;

public:
	AnimationManager();
	bool AddFromXml(const std::string& fileName); //добавляет анимации в контейнер из файла
	Animation Get(const std::string& animName, const std::string& file = "");
};

extern AnimationManager anim_mng;
#endif //ANIMATION_MANAGER_H