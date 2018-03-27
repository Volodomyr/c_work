#include "..\inc\Game.hpp"
#include <sstream>
StateControl main_state;

Game::Game() {
	gameWindow = new sf::RenderWindow();
	gameWindow->create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), (sf::String)WINDOW_TITLE);
	gameWindow->setFramerateLimit(FPS_MAX);

	main_state.SetWindow(gameWindow);
	main_state.SwitchState(STATE::PLAY);
	debugMode = true;
}

void Game::Run() {
	int frames = 0;
	sf::Clock timer;
	sf::Clock clock;

//	for (int i = 20; i < 255; i++) std::cout << (char)i << " - " << i << std::endl;

	while (!main_state.isClose()) {
		frames++;
		if (timer.getElapsedTime().asSeconds() >= 1.0f) {
			fpsValue = frames;
			frames = 0;
			timer.restart();
		}

		float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		//std::cout << time << std::endl;

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

		main_state.Update(event, _time); //-
	}
}

void Game::Draw() {
	gameWindow->clear(sf::Color::Green);
	main_state.Draw();

	if (debugMode) {
		sf::Text text;
		std::ostringstream ss;
		ss << fpsValue << std::ends;
		std::string rw = "FPS: " + ss.str();
		
		text.setString(rw.c_str());
		text.setCharacterSize(25);
		text.setFillColor(sf::Color::Red);
		text.setFont(resMngr->fonts.Get("Arial"));

		gameWindow->draw(text);
	}
	gameWindow->display();
}