#include "..\inc\StateControl.hpp"

StateControl::StateControl() {
	window = nullptr;
	curr_state = nullptr;
}

StateControl::~StateControl() {
	this->curr_state->Destroy(this->window);
	delete window;
	delete curr_state;
}

void StateControl::Destroy() {
	if (curr_state) {
		curr_state->Destroy(this->window);
	}
}

void StateControl::Draw() {
	if (curr_state) {
		this->curr_state->Draw(this->window);
	}
}

void StateControl::Update(sf::Event& event) {
	if (curr_state) {
		this->curr_state->Update(event, this->window);
	}
}

void StateControl::SetWindow(sf::RenderWindow* _window) {
	window = _window;
}

void StateControl::SetState(State *_state) {
	if (curr_state) {
		delete curr_state;
	}
	curr_state = _state;
	this->curr_state->Init(this->window);
}

void StateControl::SwitchState(const STATE& new_state) {
	delete curr_state;

	switch (new_state) {
		case PLAY: 
			curr_state = new GameState();
			break;
		case PAUSE:
			////
			break;
		case MENU:
			curr_state = new MenuState();
			break;
		case CLOSE:
			this->window->close();
			break;
	}
	this->curr_state->Init(this->window);
}
