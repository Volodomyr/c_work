#pragma once
#ifndef ANIMATION_H
#define ANIMATION_H
#include <vector>
#include <string>
#include <SFML\Graphics.hpp>
#include "ResourceManager.hpp"

class Animation {
	float speed;
	std::vector<sf::IntRect> frames;
	float curr_frame;
	sf::Sprite layer;
	bool flip;
	bool pause;
	bool loop;

public:
	Animation();
	Animation(const std::string& imageFile, sf::IntRect startFrame,
		float _speed, int step, int count);
	void SetSpeed(float _speed);
	void SetFlip(bool _flip);
	void SetFrames(std::vector<sf::IntRect> _frames);
	void SetImage(const std::string& imageFile);
	void SetLoop(bool _loop);
	float GetSpeed();
	bool GetFlip();
	auto GetFrames();
	bool GetLoop();
	Animation& operator=(const Animation& other);


	void Play();
	void Pause();
	void Update(float time, const sf::Vector2f& position);
	void Draw(sf::RenderWindow& window);
};

#endif //ANIMATION_H