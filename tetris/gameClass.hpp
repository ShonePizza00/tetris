#pragma once
#ifndef GAME_CLASS_HPP
#define GAME_CLASS_HPP
#include <vector>
#include <stdint.h>
#include "chars.hpp"
#include <random>
#include <ctime>

#define DEBUG_MODE true

#if DEBUG_MODE

#include <string>
#include <iostream>
inline void printLog(const char* str)
{
	int index = 0;
	while (str[index] != '\0')
		std::cout << str[index++];
	std::cout << '\n';
}
inline void printLog(std::string str)
{
	std::cout << str << '\n';
}
#else
inline void printLog(const char* str)
{
	return;
}

#endif // DEBUG_MODE

#define MAP_SIZE_X_GMC 10
#define MAP_SIZE_Y_GMC 20
#define SHAPES_NUM_GMC 7

struct shape
{
	char left = NULL;
	char top = NULL;
	char width = NULL;
	char height = NULL;
	char N = NULL;
	std::vector<std::vector<bool>> matrix;
};

class gameClass
{
public:
	gameClass();
	bool update(bool check);	//move down | fix and check rows
	void moveLeft();			//move left
	void moveRight();			//move right
	bool moveDown();			//move down and fix
	void rotateLeft();			// left <-^|
	void rotateRight();			// |^-> right
	uint32_t getScore();
	std::vector<std::vector<char>>& getData();
private:
	shape currentShape;
	std::vector<std::vector<char>> data;
	uint32_t score;
	inline void initNewShape()
	{
		currentShape.N = rand() % SHAPES_NUM_GMC;
		currentShape.top = 0;
		currentShape.width = charshpp::widthShapes[currentShape.N];
		currentShape.height = currentShape.N == 4 ? 1 : 2;
		currentShape.matrix.clear();
		currentShape.matrix.resize(4);
		for (int i = 0; i < 4; ++i)
			currentShape.matrix[i].resize(4);
		for (char iy = 0; iy < currentShape.height; ++iy)
			for (char ix = 0; ix < currentShape.width; ++ix)
				currentShape.matrix[iy][ix] = charshpp::shapes[currentShape.N][iy][ix];
		return;
	}
	inline void drawShape(char color)
	{
		for (char iy = 0; iy < 4; ++iy)
			for (char ix = 0; ix < 4; ++ix)
				if (currentShape.matrix[iy][ix])
					data[currentShape.top + iy][currentShape.left + ix] = color;
		return;
	}
};


#endif // !GAME_CLASS_HPP