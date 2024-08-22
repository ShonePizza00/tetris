#include "graphicsEngineClass.hpp"
#include "gameClass.hpp"
#include <ctime>
#include <Windows.h>

int main()
{
	graphicsEngineClass gec(52, 21, 15);
	const std::vector<cv::Vec3b> colorTable = {
		{ 0, 0, 0 },		//black
		{ 255, 255, 255},	//white
		{ 28, 20, 234 },	//red
		{ 46, 200, 255 },	//orange
		{ 52, 251, 254 },	//yellow
		{ 63, 218, 83 },	//green
		{ 250, 237, 1 },	//cyan
		{ 178, 10, 221 },	//purple
		{ 132, 46, 46 },	//navy
	};
	gec.setColorTable(colorTable);
	gameClass gmc;
	gec.update(gmc.getData(), gmc.getScore());
#if DEBUG_MODE && false
	std::vector<std::vector<char>> data = {
		{2,3,4,5,6,7,8,4,3,4},
		{0,0,0,0,0,0,0,0,0,0},
		{0,2,2,0,0,0,0,3,0,0},
		{0,0,2,2,0,3,3,3,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,4,4,0,0,5,5,0,0},
		{0,0,4,4,0,5,5,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,6,6,6,6,0,0,0,0},
		{0,0,0,0,0,0,0,7,0,0},
		{0,0,0,0,0,0,7,7,7,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,8,0,0,0,0,0,0,0,0},
		{0,8,8,8,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0},
	};
	gec.update(data, 12345678);
#endif

	clock_t time = clock();
	bool odd = true;
	bool leftPressed = false;
	bool rightPressed = false;
	bool downPressed = false;
	bool qPressed = false;
	bool ePressed = false;
	while (1)
	{
		if ((GetAsyncKeyState(VK_LEFT) & 0x8000))
		{
			if (!leftPressed)
			{
				leftPressed = true;
				gmc.moveLeft();
				gec.update(gmc.getData(), gmc.getScore());
			}
		}
		else
			leftPressed = false;
		if (GetKeyState(VK_RIGHT) & 0x8000)
		{
			gmc.moveRight();
			gec.update(gmc.getData(), gmc.getScore());
		}
		if (GetKeyState(VK_DOWN) & 0x8000)
		{
			odd = gmc.moveDown();
			gec.update(gmc.getData(), gmc.getScore());
		}
		if (GetKeyState('Q') & 0x8000)
		{

		}
		if (GetKeyState('E') & 0x8000)
		{

		}
		clock_t tTime = clock();
		if (tTime - time >= 1000)
		{
			if (odd)
			{
				gec.update(gmc.getData(), gmc.getScore());
				odd = gmc.update(true);
			}
			/*if (odd)
			{
				gmc.moveLeft();
				gec.update(gmc.getData(), gmc.getScore());
				odd = false;
			}
			else
			{
				gmc.moveRight();
				gec.update(gmc.getData(), gmc.getScore());
				odd = true;
			}*/
			//gmc.update();
			//gec.update(gmc.getData(), gmc.getScore());
			time = tTime;
		}
	}
	return 0;
}