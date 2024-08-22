#pragma once
#ifndef GRAPHICS_ENGINE_CLASS_HPP
#define GRAPHICS_ENGINE_CLASS_HPP
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include "chars.hpp"
#include <stdint.h>

//#include <iostream>
//#include <ctime>

#define MAP_SIZE_X_GEC 10
#define MAP_SIZE_Y_GEC 20
#define MAP_SCORE_X_POS_GEC 15
#define MAP_SCORE_Y_POS_GEC 3
#define MAP_SCORE_N_X_POS_GEC 15
#define MAP_SCORE_N_Y_POS_GEC 10
#define MAP_SCORE_INTS_NUM_GEC 8

typedef cv::Vec3b color_t;

class graphicsEngineClass
{
public:
	graphicsEngineClass();
	graphicsEngineClass(int x, int y, int size);
	void setColorTable(const std::vector<color_t>& colorTable);
	~graphicsEngineClass();
	void update(std::vector<std::vector<char>>& data, uint32_t score);

private:
	inline void drawPixel(uint32_t x, uint32_t y, color_t c)
	{
		for (uint32_t iy = 0; iy < this->pixelSize; ++iy)
			for (uint32_t ix = 0; ix < this->pixelSize; ++ix)
				this->screen.at<cv::Vec3b>(y * this->pixelSize + iy, x * this->pixelSize + ix) = c;
	}
	std::vector<color_t> colorTable;
	const color_t whiteC = color_t(0xFF, 0xFF, 0xFF);
	cv::Mat screen;
	std::vector<std::vector<char>> dataCopy;
	uint32_t scoreCopy;
	uint32_t pixelSize = NULL;
	int sizeY = NULL;
	int sizeX = NULL;
	const std::vector<std::vector<std::vector<bool>>>& chars = charshpp::chars;
	const std::vector<char>& offsetChars = charshpp::offsetChars;
};


#endif // !GRAPHICS_ENGINE_CLASS_HPP