#include "Credits.h"
#include "raylib.h"

void Credits::InCredits()
{
	
	CheckInput();
	DrawCredits();
}

void Credits::DrawCredits()
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenHeight() / screenHeight;

	Font font = GetFontDefault();
	DrawText("Credits:", 10 * windowReSizeWidth, 10 * windowReSizeHeight, 40, BLACK);
	DrawText("Creator: Pablo Goldman",10 * windowReSizeWidth, 60 * windowReSizeHeight, 40, BLACK);
	DrawText("Music By: Lautaro Bianco", 10 * windowReSizeWidth, 110 * windowReSizeHeight, 40 , BLACK);
	DrawText("Library Creator: Raysan", 10 * windowReSizeWidth, 160 * windowReSizeHeight, 40, BLACK);
	DrawText("Click any part of the screen to continue...", 10 * windowReSizeWidth, 400 * windowReSizeHeight, 30, BLACK);
}

void Credits::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Credits::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Credits::CheckInput()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		ReturnToMenu();
	}
}
