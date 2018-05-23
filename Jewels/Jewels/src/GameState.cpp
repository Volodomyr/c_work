#include "..\inc\GameState.hpp"

GameState::GameState(sf::RenderWindow& _window) {
	game_bg.SetImage("game_bg2");

	grid = new Grid(_window);
	grid->Generate();
	grid->CellDistribute();

	textBlock = new sf::RectangleShape;
	textBlock->setSize(sf::Vector2f(_window.getSize().x / 4.8f, _window.getSize().y / 2.4f));
	textBlock->setPosition(0.76f * _window.getSize().x, grid->GetPosition().y);
	textBlock->setFillColor(sf::Color(39, 103, 147, 150));
	textBlock->setOutlineThickness(2.5);
	textBlock->setOutlineColor(sf::Color(93, 133, 159));

	maxScore = 0;
	std::ifstream in("data.dta");
	if (in.is_open())
	{
		in >> maxScore;
		in.close();
	}

	scoreText = new Text("Score: " + Text::ToString(scoreValue), FONT_SIZE);
	scoreText->SetPosition(sf::Vector2f(textBlock->getPosition().x + textBlock->getSize().x / 6.0f,
		textBlock->getPosition().y + textBlock->getSize().y / 8.0f));
	
	maxScoreText = new Text("Best score: " + Text::ToString(scoreValue), FONT_SIZE);
	maxScoreText->SetPosition(sf::Vector2f(textBlock->getPosition().x + textBlock->getSize().x / 6.0f,
		textBlock->getPosition().y + textBlock->getSize().y * 1.94f / 8.0f));


	std::ostringstream os;
	os << timer.getElapsedTime().asSeconds() << std::ends;

	timerText = new Text("Lost time: " + os.str(), FONT_SIZE);
	timerText->SetPosition(sf::Vector2f(textBlock->getPosition().x + textBlock->getSize().x / 6.0f,
		textBlock->getPosition().y + textBlock->getSize().y * 2.15f / 6.0f));


	timer.restart();
	gamePlay = true;
	textEnd = new Text("Game over!!!",60);
	textEnd->SetColor(sf::Color::Cyan);
	textEnd->SetThickness(2);
	textEnd->SetPosition(sf::Vector2f(_window.getSize().x / 2.0f - textEnd->GetRect().width / 2.0f,
					    _window.getSize().y / 2.0f - textEnd->GetRect().height / 2.0f));
	valueFixed = false;
}

void GameState::Update(sf::RenderWindow& window, float _time) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		std::ofstream out("data.dta");
		out << maxScore;
		out.close();
		main_state.SwitchState(STATE::MENU);
		return;
	}

	if (gamePlay) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)) {
			grid->Generate();
			grid->CellDistribute();
		}
		grid->Update(window, _time);

		/*time update*/
		std::ostringstream os;
		int diff_time = TIME_MAX * 60 - (int)timer.getElapsedTime().asSeconds();

		if (diff_time >= 0) {
			std::string _null = "";
			if (diff_time % 60 >= 0 && diff_time % 60 <= 9) {
				_null = "0";
			}
			os << diff_time / 60 << ":" << _null << diff_time % 60 << std::ends;
			timerText->SetString("Lost time:  " + os.str());
		}
		else {
			gamePlay = false;
			if (!valueFixed) {
				std::ofstream out("data.dta");
				out << maxScore;
				out.close();
				valueFixed = true;
			}
		}

		/*max_score update*/
		if (scoreValue > maxScore) {
			maxScore = scoreValue;
		}

		scoreValue = SCORE_FOR_CELL * grid->GetPointsValue();
		scoreText->SetString("Score: " + Text::ToString(scoreValue));
		maxScoreText->SetString("Best score: " + Text::ToString(maxScore));
	}
}

void GameState::Draw(sf::RenderWindow &window) {
	window.draw(*textBlock);
	grid->Draw(window);
	scoreText->Draw(window);
	maxScoreText->Draw(window);
	timerText->Draw(window);

	if (!gamePlay) {
		textEnd->Draw(window);
	}
}

void GameState::Destroy() {
	delete grid;
	delete scoreText;
	delete maxScoreText;
	delete timerText;
	delete textBlock;
	delete textEnd;
}
