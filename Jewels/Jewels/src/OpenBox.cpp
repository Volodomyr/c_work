#include "..\inc\OpenBox.hpp"

OpenBox::OpenBox(): Box() {
	rect->setFillColor(BOX_COLOR); //ставим черный полупрозрачный цвет
	rect->setOutlineThickness(BOX_BORDER);
	rect->setOutlineColor(BOX_BORDER_COLOR);

	sprite = new sf::Sprite;
	sprite->setPosition(*position);

	value = 0;
	offset = 0;
	swap_state = false;
	moved = false;
	direction = NONE;
}

OpenBox::~OpenBox() {
	delete sprite;
}

void OpenBox::SetPosition(float x, float y) {
	*position = sf::Vector2f(x, y);
	rect->setPosition(*position);
	sprite->setPosition(*position);
}

void OpenBox::Update(sf::RenderWindow& window, float time) {
	sprite->setTexture(resMng->textures.Get("boxes"));
	sprite->setTextureRect(sf::IntRect(this->value * BOX_SIZE, 0, BOX_SIZE, BOX_SIZE));

	if (offset != 0) {
		this->Move(time);
	}
}

bool OpenBox::isClicked(sf::RenderWindow& window) {
	return events.isClicked(rect->getGlobalBounds(), window);
}

void OpenBox::Draw(sf::RenderWindow& window) {
	window.draw(*rect);
	window.draw(*sprite);
}

void OpenBox::SetValue(unsigned short _value) {
	value = _value;
}

void OpenBox::SetTexture(const sf::Texture& _texture) {
	sprite->setTexture(_texture);
}

void OpenBox::SetTexture(const sf::Texture& _texture, const sf::IntRect& _rect) {
	sprite->setTexture(_texture);
	sprite->setTextureRect(_rect);
}

sf::Texture OpenBox::GetTexture() {
	return *sprite->getTexture();
}

unsigned short OpenBox::GetValue() {
	return value;
}

sf::Vector2f OpenBox::GetOffset(DIRECTION dir, float time) {
	sf::Vector2f res;
	float shift = MOVE_SPEED * time;

	switch (dir) {
		case RIGHT:
			res.x = shift;
			res.y = 0;
			break;
		case LEFT:
			res.x = -shift;
			res.y = 0;
			break;
		case UP:
			res.x = 0;
			res.y = -shift;
			break;
		case DOWN:
			res.x = 0;
			res.y = shift;
			break;
	}

	return res;
}

void OpenBox::Move(float time) {
	sf::Vector2f ds = this->GetOffset(direction, time);

	if (offset > 0) {
		sprite->move(ds.x, ds.y);
		offset -= MOVE_SPEED * time;
	}
	else if (offset < 0) {
		sf::Vector2f target = *this->position;
		if (!ds.x) {
			target += { 0, abs(ds.y) / ds.y * (BOX_SIZE + BOX_BORDER) };
		}
		else if (!ds.y) {
			target += { abs(ds.x) / ds.x * (BOX_SIZE + BOX_BORDER), 0 };
		}
		
		offset = 0;
		direction = NONE;
		moved = !moved;
		if (moved) {
			sprite->setPosition(target);
		}
		else {
			sprite->setPosition(*this->position);
		}
	}
}

void OpenBox::SetDirection(DIRECTION _dir) {
	this->direction = _dir;
}

void OpenBox::Slide(DIRECTION _dir) {
	this->direction = _dir;
	this->offset = BOX_SIZE;
	swap_state = false;
}

void OpenBox::BackToOrigin() {
	this->sprite->setPosition(*position);
	this->rect->setPosition(*position);
}

void OpenBox::SetMatch(bool _match) {
	match = _match;
}

bool OpenBox::GetMatch() {
	return match;
}