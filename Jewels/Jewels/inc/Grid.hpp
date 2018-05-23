#pragma once
#ifndef GRID_H
#define GRID_H
#include <vector>
#include "Box.hpp"
#include "OpenBox.hpp"
#include <ctime>
#include <iostream>
#include <Windows.h>
#include <algorithm>
const size_t GRID_SIZE = 8;
const size_t BOX_TYPES = 6;
using Matrix = std::vector< std::vector<OpenBox> >;

enum GRID_STATE {
	NUL = 0,
	SWAP,
	FIND_MATCH,
	SHIFT_LINES,
};

class Grid {
	sf::Vector2f *position;
	sf::Vector2f *size;
	sf::Vector2i *markedBox;
	sf::Vector2i *movedBox;
	sf::Sound *sound;
	Box *bound;
	size_t rows;
	size_t cols;
	bool showBound;
	bool cellSwap;
	GRID_STATE state;
	std::vector< std::vector<OpenBox> > cells;
	unsigned points;

	bool AllowedMove(int x, int y);
	DIRECTION IdentifyDirection(int x, int y);
	void SwapCells(OpenBox& first, OpenBox& second);
	void FindingMatch();
	bool ConsistMatchInLine(int i, int j);
	void ShiftLines();
	int RandomValue(int v1, int v2 = 0);
	void SwapValues(OpenBox& first, OpenBox& second);
	GRID_STATE StateProcessing(GRID_STATE _state);
	bool isCorrectIndex(size_t index, size_t max);
	unsigned MatchCount();

public:
	Grid(const sf::RenderWindow& window);
	~Grid();
	void Generate();
	void DeleteCopies();
	void CellDistribute();
	bool ConsistMatch(Matrix& _cells);
	
	unsigned GetPointsValue();
	void Update(sf::RenderWindow& window, float _time);
	void Draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() { return cells[0][0].GetPosition(); }
	Matrix GetCells() { return cells; }

};

#endif //GRID_H