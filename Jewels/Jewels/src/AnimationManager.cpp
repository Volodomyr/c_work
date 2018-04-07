#include "..\inc\AnimationManager.hpp"

AnimationManager::AnimationManager():
	folder("resources/animations/") {
}

bool AnimationManager::AddFromXml(const std::string& fileName) {
	bool exist = false;
	TiXmlDocument file((folder + fileName).c_str());
	if (file.LoadFile()) {
		exist = true;
	}

	TiXmlElement *sprites = file.FirstChildElement("sprites");
	TiXmlElement *animation = sprites->FirstChildElement("animation");

	while (animation) {
		Animation new_anim;
		
		std::string key = animation->Attribute("title");
		float delay = 1.f / std::stoi(animation->Attribute("delay"));

		TiXmlElement *cut = animation->FirstChildElement("cut");
		std::vector<sf::IntRect> frames;

		while (cut) {
			sf::IntRect rect;
			rect.width = std::stoi(cut->Attribute("w"));
			rect.left = std::stoi(cut->Attribute("x"));
			rect.top = std::stoi(cut->Attribute("y"));
			rect.height = std::stoi(cut->Attribute("h"));

			frames.push_back(rect);
			cut = cut->NextSiblingElement("cut");
		}

		std::string imageName = sprites->Attribute("image");
		imageName.erase(imageName.find('.'), 4);
	
		new_anim.SetImage(imageName);
		new_anim.SetFrames(frames);
		new_anim.SetSpeed(ANIMATION_SPEED * delay);

		m_animations.insert(std::make_pair(key, new_anim));
		animation = animation->NextSiblingElement("animation");
	}
	return exist;
}

Animation AnimationManager::Get(const std::string& animName, 
	const std::string& file) {
	if (m_animations.find(animName) != m_animations.end()) {
		return m_animations[animName];
	}
	
	if (!file.empty()) {
		this->AddFromXml(file);
	}

	return m_animations.at(animName);
}