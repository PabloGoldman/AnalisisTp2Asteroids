#include "Rules.h"
#include "raylib.h"

const int fontSize = 28;

void Rules::InRules()
{
	CheckInput();
	DrawRules();
}

void Rules::DrawRules()
{
	Font font = GetFontDefault();
	DrawText("You control the player with the mouse", 10, 10, fontSize, BLACK);
	DrawText("Right click to accelerate", 10, 60, fontSize, BLACK);
	DrawText("Left click to shoot", 10, 110, fontSize, BLACK);
	DrawText("Click any part of the screen to continue...", 10, 400, 30, BLACK);
}

void Rules::SetSceneManager(SceneManager* sm)
{
	scene = sm;
}

void Rules::ReturnToMenu()
{
	scene->SetSceneManager(Scene::MENU);
}

void Rules::CheckInput()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		ReturnToMenu();
	}
}
