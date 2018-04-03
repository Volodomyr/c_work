#pragma once
#ifndef GRID_H
#define GRID_H
#include <vector>
#include "Box.hpp"
#include "OpenBox.hpp"
#include <ctime>
#include <iostream>
#include <Windows.h>
const size_t GRID_SIZE = 8;
const size_t BOX_TYPES = 6;

class Grid {
	sf::Vector2f *position;
	sf::Vector2f *size;
	sf::Vector2i *markedBox;
	sf::Vector2i *movedBox;

	Box *bound;
	size_t rows;
	size_t cols;
	bool showBound;
	std::vector< std::vector<OpenBox> > cells;

	bool AllowedMove(int x, int y);
	DIRECTION IdentifyDirection(int x, int y);
	void SwapCells(OpenBox& first, OpenBox& second);
	bool FindingMatch(int i, int j);
	int RandomValue(int v1, int v2 = 0);
	void SwapValues(OpenBox& first, OpenBox& second);

public:
	Grid(const sf::RenderWindow& window);
	~Grid();
	void Generate();
	void DeleteCopies();
	void Update(sf::RenderWindow& window, float _time);
	void Draw(sf::RenderWindow& window);

};

#endif //GRID_H