#include "..\inc\Animation.hpp"

Animation::Animation(const std::string& imageFile, sf::IntRect startFrame,
	float _speed,int step, int count) 
{
	layer.setTexture(resMng->getTexture(imageFile));
	frames.push_back(startFrame);
	for (int i = 1; i < count; ++i) {
		frames.push_back(sf::IntRect(frames[0].left + i * step,
			frames[0].top, frames[0].width, frames[0].height));
	}
	pause = false;
	flip = false;
	loop = false;
	curr_frame = 0;
	speed = _speed;
}

Animation::Animation() {
	pause = false;
	flip = false;
	loop = false;
	curr_frame = 0;
	speed = 0;
}

void Animation::SetSpeed(float _speed) {
	speed = _speed;
}

void Animation::SetFlip(bool _flip) {
	flip = _flip;
}

float Animation::GetSpeed() {
	return speed;
}

bool Animation::GetFlip() {
	return flip;
}

void Animation::Play() {
	pause = false;
}
void Animation::Pause() {
	pause = true;
}
void Animation::Update(float time,const sf::Vector2f& position) {
	if (!pause) {
		curr_frame += time * speed;
		if (curr_frame > frames.size()) {	
			if (!loop) {
				speed = 0;
				curr_frame -= 0.5f;
			}
			else {
				curr_frame = 0.f;
			}
		}

		sf::IntRect animRect = frames[(int)curr_frame];
		if (flip) {
			animRect.left += animRect.width;
			animRect.width = -animRect.width;
		}

		layer.setTextureRect(animRect);
		layer.setPosition(position);
			
	}
}

void Animation::Draw(sf::RenderWindow& window) {
	window.draw(layer);
}

void Animation::SetFrames(std::vector<sf::IntRect> _frames) {
	frames = _frames;
}

auto Animation::GetFrames() {
	return frames;
}

void Animation::SetImage(const std::string& imageFile) {
	layer.setTexture(resMng->getTexture(imageFile));
}

Animation& Animation::operator=(const Animation& other) {
	if (&other == this) {
		return *this;
	}

	speed = other.speed;
	curr_frame = other.curr_frame;
	layer = other.layer;
	flip = other.flip;
	pause = other.pause;
	frames = other.frames;
	
	return *this;
}

void Animation::SetLoop(bool _loop) {
	loop = _loop;
}

bool Animation::GetLoop() {
	return loop;
}