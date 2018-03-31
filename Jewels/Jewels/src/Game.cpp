#include "..\inc\Game.hpp"
#include <sstream>

StateControl main_state;
Background game_bg;
//sf::Event game_event;
Event events;

Game::Game() {
	gameWindow = new sf::RenderWindow();
	gameWindow->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), (sf::String)WINDOW_TITLE);
	gameWindow->setKeyRepeatEnabled(false);
	
	main_state.SetWindow(gameWindow);
	main_state.SwitchState(STATE::PLAY);
	debugMode = true;
}

void Game::Run() {
	int frames = 0;
	sf::Clock timer;
	sf::Clock clock;

	while (!main_state.isClose()) {
		frames++;
		if (timer.getElapsedTime().asSeconds() >= 1.0f) {
			fpsValue = frames;
			frames = 0;
			timer.restart();
		}

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		this->Update(time);
		this->Draw();
	}
}

Game::~Game() {
	if (gameWindow->isOpen()) {
		gameWindow->close();
	}
	delete gameWindow;
}

void Game::Update(float _time) {
	sf::Event event;
	while (gameWindow->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			main_state.SwitchState(STATE::CLOSE);
		}

		if (event.type == sf::Event::KeyPressed
			&& event.key.code == sf::Keyboard::Tilde) {
			debugMode ^= 1;
		}

		events.SetEventActive(true);
		events.SetEvent(event);
	}
	main_state.Update(_time);
	//sf::sleep(sf::Time(sf::milliseconds(100)));
}

void Game::Draw() {
	gameWindow->clear(sf::Color::Green);
	game_bg.Draw(*gameWindow);
	main_state.Draw();

	if (debugMode) {
		sf::Text text;
		std::ostringstream ss;
		ss << fpsValue << std::ends;
		std::string rw = "FPS: " + ss.str();
		
		text.setString(rw.c_str());
		text.setCharacterSize(25);
		text.setFillColor(sf::Color::Red);
		text.setFont(resMng->fonts.Get("Arial"));

		gameWindow->draw(text);
	}
	gameWindow->display();
}