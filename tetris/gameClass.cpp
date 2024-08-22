#include "gameClass.hpp"

gameClass::gameClass()
{
	printLog("gameClass constructor: resize game map 20x10\0");
	this->data = std::vector<std::vector<char>>(
		MAP_SIZE_Y_GMC,
		std::vector<char>(MAP_SIZE_X_GMC, 0)
		);
	printLog("gameClass constructor: score = 0\0");
	this->score = 0;
	printLog("gameClass constructor: init first shape\0");
	srand((uint32_t)time(NULL));
	initNewShape();
	this->currentShape.left = (MAP_SIZE_X_GMC - charshpp::widthShapes[this->currentShape.N]) >> 1;
	printLog("gameClass constructor: draw first shape\0");
	drawShape(2 + currentShape.N);
}

uint32_t gameClass::getScore()
{
	printLog("gameClass: getScore()\0");
	return score;
}

std::vector<std::vector<char>>& gameClass::getData()
{
	printLog("gameClass: getData()\0");
	return data;
}

void gameClass::moveLeft()
{
	clock_t time = clock();
	if (this->currentShape.left > 0)
	{
		bool f = true;
		for (char iy = 0; iy < this->currentShape.height; ++iy)
			if (this->currentShape.matrix[iy][0] &&
				this->data[this->currentShape.top + iy][this->currentShape.left - 1])
			{
				f = false;
				break;
			}
		if (f)
		{
			drawShape(0);
			this->currentShape.left -= 1;
			drawShape(2 + this->currentShape.N);
		}
	}
	printLog("gameClass: moveLeft: " + std::to_string(clock() - time));
}

void gameClass::moveRight()
{
	clock_t time = clock();
	if (this->currentShape.left + this->currentShape.width < MAP_SIZE_X_GMC)
	{
		bool f = true;
		for (char iy = 0; iy < this->currentShape.height; ++iy)
			if (this->currentShape.matrix[iy][this->currentShape.width - 1] &&
				this->data[this->currentShape.top + iy][this->currentShape.left + this->currentShape.width])
			{
				f = false;
				break;
			}
		if (f)
		{
			drawShape(0);
			this->currentShape.left += 1;
			drawShape(2 + this->currentShape.N);
		}
	}
	printLog("gameClass: moveRight: " + std::to_string(clock() - time));
}

bool gameClass::update(bool check)		//false: end; true: continue
{
	//move down
	clock_t time = clock();
	if (this->currentShape.top + this->currentShape.height < MAP_SIZE_Y_GMC && check)
	{
		bool f = true;
		for (char ix = 0; ix < this->currentShape.width; ++ix)
		{
			char iy = this->currentShape.height - 1;
			while (!this->currentShape.matrix[iy][ix]) { --iy; }
			if (this->data[iy + 1 + this->currentShape.top][this->currentShape.left + ix])
			{
				f = false;
				break;
			}

		}
		if (f)
		{
			drawShape(0);
			this->currentShape.top += 1;
			drawShape(2 + this->currentShape.N);
			return true;
		}
	}
	/*
	* fix:
	* remove full rows
	* increase scoreAdd
	* update score;
	* init new shape;
	* check shape cand be placed;
	*/
	uint32_t scoreAdd = 0;
	for (char iy = 0; iy < this->currentShape.height; ++iy)
	{
		bool f = true;
		for (char ix = 0; ix < MAP_SIZE_X_GMC; ++ix)
			if (!this->data[iy + this->currentShape.top][ix])
			{
				f = false;
				break;
			}
		if (f)
		{
			scoreAdd += 100;
			for (char iiy = iy + this->currentShape.top; iiy > 0; --iiy)
				this->data[iiy] = this->data[iiy - 1];
			this->data[0] = std::vector<char>(MAP_SIZE_X_GMC, 0);
		}
	}
	this->score += scoreAdd;
	initNewShape();
	bool f = true;
	for (char iy = 0; iy < this->currentShape.height; ++iy)
		for (char ix = 0; ix < this->currentShape.width; ++ix)
			if (this->currentShape.matrix[iy][ix] &&
				this->data[iy][ix])
			{
				f = false;
				break;
			}
	if (f)
		drawShape(2 + this->currentShape.N);

	printLog("gameClass: update: " + std::to_string(clock() - time));
	return f;
}

bool gameClass::moveDown()
{
	clock_t time = clock();
	bool f = true;
	drawShape(0);
	while (f && (this->currentShape.top + this->currentShape.height < MAP_SIZE_Y_GMC))
	{
		for (char ix = 0; ix < this->currentShape.width; ++ix)
		{
			char iy = this->currentShape.height - 1;
			while (!this->currentShape.matrix[iy][ix]) { --iy; }
			if (this->data[iy + 1 + this->currentShape.top][this->currentShape.left + ix])
			{
				f = false;
				break;
			}
		}
		if (f)
			this->currentShape.top += 1;
	}
	drawShape(2 + this->currentShape.N);
	printLog("gameClass: moveDown: " + std::to_string(clock() - time));
	return update(false);
}

void gameClass::rotateLeft()
{

}

void gameClass::rotateRight()
{

}