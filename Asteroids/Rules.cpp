#include "Rules.h"
#include "raylib.h"

const int fontSize = 40;

void Rules::InRules()
{
	CheckInput();
	DrawRules();
}

void Rules::DrawRules()
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenHeight() / screenHeight;

	Font font = GetFontDefault();
	DrawText("You control the player with the mouse", 10 * windowReSizeWidth, 10 * windowReSizeHeight, fontSize, BLACK);
	DrawText("Right click to accelerate", 10 * windowReSizeWidth, 60 * windowReSizeHeight, fontSize, BLACK);
	DrawText("Left click to shoot", 10 * windowReSizeWidth, 110 * windowReSizeHeight, fontSize, BLACK);
	DrawText("Click any part of the screen to continue...", 10 * windowReSizeWidth, 400 * windowReSizeHeight, 30, BLACK);
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
