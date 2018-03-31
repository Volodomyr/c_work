#pragma once
#ifndef EVENT_H
#define EVENT_H
#include <SFML\Graphics.hpp>

class Event {
	sf::Event currEvent;
	bool active;
	
public:
	Event() {
		active = true;
	}

	void SetEvent(const sf::Event& _currEvent) {
		currEvent = _currEvent;
	}

	void SetEventActive(bool _active) {
		active = _active;
	}

	bool isPointed(const sf::FloatRect& rect, const sf::RenderWindow& window) {
		if (window.isOpen() && active) {
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
			return rect.contains(sf::Vector2f(mouse_pos));
		}
		return false;
	}

	bool isClicked(const sf::FloatRect& rect, const sf::RenderWindow& window) {
		if (active && this->isPointed(rect, window) 
			&& currEvent.type == sf::Event::MouseButtonPressed) {
			active = false;
			return currEvent.mouseButton.button == sf::Mouse::Left;
		}
		return false;
	}

	sf::Event GetEvent() {
		return currEvent;
	}
};

extern Event events;
#endif //EVENT_H