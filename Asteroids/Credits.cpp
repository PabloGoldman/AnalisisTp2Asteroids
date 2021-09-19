#include "Credits.h"
#include "raylib.h"

void Credits::InCredits()
{
	CheckInput();
	DrawCredits();
}

void Credits::DrawCredits()
{
	Font font = GetFontDefault();
	DrawText("Credits:", 10, 10, 40, BLACK);
	DrawText("Creator: Pablo Goldman", 10, 60, 40, BLACK);
	DrawText("Music By: Lautaro Bianco", 10, 110, 40, BLACK);
	DrawText("Library Creator: Raysan", 10, 160, 40, BLACK);
	DrawText("Click any part of the screen to continue...", 10, 400, 30, BLACK);
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
