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
	DrawText("Logo designer: Fermin Gimpel", 10, 110, 40, BLACK);
	DrawText("Music By: Lautaro Bianco", 10, 160, 40, BLACK);
	DrawText("Library Creator: Raysan", 10, 210, 40, BLACK);
	DrawText("Press enter to continue...", 10, 400, 40, BLACK);
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
	if (IsKeyReleased(KEY_ENTER))
	{
		ReturnToMenu();
	}
}
