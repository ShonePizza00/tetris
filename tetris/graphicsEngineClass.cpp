#include "graphicsEngineClass.hpp"

graphicsEngineClass::graphicsEngineClass()
{
	pixelSize = 1;
	this->sizeY = 21;
	this->sizeX = 32;
	throw std::exception("not good idea!");
}

graphicsEngineClass::graphicsEngineClass(int x, int y, int size)
{
	this->pixelSize = size;
	this->sizeY = y;
	this->sizeX = x;
	this->screen = cv::Mat(y * size, x * size, CV_8UC3, cv::Scalar(0, 0, 0));
	for (uint32_t iiy = 0; iiy <= MAP_SIZE_Y_GEC; ++iiy)
	{
		drawPixel(0, iiy, whiteC);
		drawPixel(MAP_SIZE_X_GEC + 1, iiy, whiteC);
	}
	for (uint32_t iix = 1; iix <= MAP_SIZE_X_GEC; ++iix)
		drawPixel(iix, MAP_SIZE_Y_GEC, whiteC);
	uint32_t offset = 0;
	for (uint32_t iy = 0; iy < 5; ++iy)
	{
		for (uint32_t iiy = 0; iiy < 5; ++iiy)
		{
			for (uint32_t iix = 0; iix < 5; ++iix)
			{
				if (chars[iy][iiy][iix])
					drawPixel(MAP_SCORE_X_POS_GEC + offset + iix,
						MAP_SCORE_Y_POS_GEC + iiy, whiteC);
			}
		}
		offset += (5 - offsetChars[iy]);
	}
	offset = 0;
	for (uint32_t iy = 0; iy < MAP_SCORE_INTS_NUM_GEC; ++iy)
	{
		for (uint32_t iiy = 0; iiy < 5; ++iiy)
		{
			for (uint32_t iix = 0; iix < 3; ++iix)
			{
				if (chars[5][iiy][iix])
					drawPixel(MAP_SCORE_N_X_POS_GEC + offset + iix,
						MAP_SCORE_N_Y_POS_GEC + iiy, whiteC);
			}
		}
		offset += (5 - offsetChars[5]);
	}
	this->dataCopy = std::vector<std::vector<char>>(
		MAP_SIZE_Y_GEC,
		std::vector<char>(MAP_SIZE_X_GEC, 0)
	);
	scoreCopy = 0;
	cv::imshow("Game", screen);
	cv::waitKey(1);
}


graphicsEngineClass::~graphicsEngineClass()
{
	colorTable.clear();
}

void graphicsEngineClass::setColorTable(const std::vector<color_t>& colorTable)
{
	this->colorTable = colorTable;
}

void graphicsEngineClass::update(std::vector<std::vector<char>>& data, uint32_t score)
{
	//clock_t time = clock();
	if (scoreCopy != score)
	{
		uint32_t t = score;
		uint16_t k = 0;
		uint32_t rev = 0;
		while (t)
		{
			rev *= 10;
			rev += t % 10;
			t /= 10;
			++k;
		}
		uint16_t offset = 0;
		for (uint16_t n = k; n < MAP_SCORE_INTS_NUM_GEC; ++n)
		{
			for (uint32_t iiy = 0; iiy < 5; ++iiy)
			{
				for (uint32_t iix = 0; iix < 3; ++iix)
				{
					drawPixel(MAP_SCORE_N_X_POS_GEC + offset + iix,
						MAP_SCORE_N_Y_POS_GEC + iiy, colorTable[chars[5][iiy][iix]]);
				}
			}
			offset += (5 - offsetChars[5]);
		}
		for (; k > 0; --k)
		{
			for (uint16_t iiy = 0; iiy < 5; ++iiy)
				for (uint16_t iix = 0; iix < 3; ++iix)
				{
					drawPixel(MAP_SCORE_N_X_POS_GEC + offset + iix,
						MAP_SCORE_N_Y_POS_GEC + iiy, colorTable[chars[5 + rev % 10][iiy][iix]]);
				}
			offset += (5 - offsetChars[5 + rev % 10]);
			rev /= 10;
		}
		scoreCopy = score;
	}
	for (uint32_t y = 0; y < MAP_SIZE_Y_GEC; ++y)
		for (uint32_t x = 1; x <= MAP_SIZE_X_GEC; ++x)
			if (dataCopy[y][x - 1] != data[y][x - 1])
				drawPixel(x, y, colorTable[data[y][x - 1]]);
	dataCopy = data;
	//std::cout << "graphics: update: " + std::to_string(clock() - time) << '\n';
	cv::imshow("Game", screen);
	cv::waitKey(1);
	return;
}
