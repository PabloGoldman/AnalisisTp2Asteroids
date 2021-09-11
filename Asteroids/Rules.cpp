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
	DrawText("Left player controls are  | W , S |", 10, 10, fontSize, BLACK);
	DrawText("Right player controls are |Up arrow , Down arrow| ", 10, 60, fontSize, BLACK);
	DrawText("First player to reach 10 points win the game", 10, 110, fontSize, BLACK);
	DrawText("If a player hits 7 points, the other player will get a buff!", 10, 160, fontSize, BLACK);
	DrawText("Take care if both players reach 7 points!", 10, 210, fontSize, BLACK);
	DrawText("Press |P| to pause the game while playing", 10, 260, fontSize, BLACK);
	DrawText("Press enter to continue...", 10, 400, fontSize, BLACK);
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
	if (IsKeyReleased(KEY_ENTER))
	{
		ReturnToMenu();
	}
}
