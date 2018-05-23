#include "..\inc\StateControl.hpp"

StateControl::StateControl() {
	window = nullptr;
	curr_state = nullptr;
	isGameClose = false;
}

StateControl::~StateControl() {
	if (curr_state) {
		this->curr_state->Destroy();
		delete curr_state;
	}
}

void StateControl::Destroy() {
	if (curr_state) {
		curr_state->Destroy();
	}
}

void StateControl::Draw() {
	if (curr_state) {
		this->curr_state->Draw(*window);
	}
}

void StateControl::Update(float _time) {
	if (curr_state) {
		this->curr_state->Update(*window, _time);
	}
}

void StateControl::SetWindow(sf::RenderWindow* _window) {
	window = _window;
}

void StateControl::SetState(State *_state) {
	this->Destroy();
	if (curr_state) {
		delete curr_state;
	}
	curr_state = _state;
}

void StateControl::SwitchState(const STATE& new_state) {
	if (new_state == STATE::CLOSE) {
		isGameClose = true;
		return;
	}

	//this->Destroy();
	delete curr_state;
	curr_state = nullptr;
	

	switch (new_state) {
		case PLAY: 
			curr_state = new GameState(*this->window);
			break;
		case PAUSE:
			////
			break;
		case MENU:
			curr_state = new MenuState(*this->window);
			break;
		case INFO:
			curr_state = new InfoState(*this->window);
			break;
	}
}
