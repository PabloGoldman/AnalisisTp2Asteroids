#include "HUD.h"

void HUD::DrawPoints(int points, int posX, int posY, int fontSize, Color color)
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenHeight() / screenHeight;

	DrawText(TextFormat("%i", points), posX * windowReSizeWidth, posY * windowReSizeHeight, fontSize * windowReSizeHeight, color);
}
