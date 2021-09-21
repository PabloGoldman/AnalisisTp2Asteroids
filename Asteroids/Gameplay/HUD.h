#pragma once
#include "raylib.h"

class HUD
{
private:
	const float screenWidth = 800;
	const float screenHeight = 450;

	float windowReSizeWidth = GetScreenWidth() / screenWidth;
	float windowReSizeHeight = GetScreenHeight() / screenHeight;

public:

	void DrawPoints(int points, int posX, int posY, int fontSize, Color color);

};

