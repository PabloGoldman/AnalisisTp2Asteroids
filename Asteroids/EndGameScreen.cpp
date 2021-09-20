#include "EndGameScreen.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

EndGameScreen::EndGameScreen()
{

	replay = new Button();
	quit = new Button();

	player1Win = false;
}

EndGameScreen::~EndGameScreen()
{
	delete replay;
	delete quit;
}

ENDGAMEOPTION EndGameScreen::GetOption()
{
	return option;
}

void EndGameScreen::InEndGameScreen()
{
	CheckInput();
	Update();
	DrawEndGameScreen();
}

void EndGameScreen::SetOption(ENDGAMEOPTION _option)
{
	option = _option;
}

void EndGameScreen::CheckInput()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), replay->GetRectangle()))
		{
			sceneManager->SetSceneManager(Scene::GAME);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), quit->GetRectangle()))
		{
			sceneManager->SetSceneManager(Scene::MENU);
		}
	}
}

void EndGameScreen::DrawEndGameScreen()
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenHeight() / screenHeight;

	Font font = GetFontDefault();

	DrawRectangle((screenWidth / 2 - 220) * windowReSizeWidth, (screenHeight/2 - 200) * windowReSizeHeight, 500 * windowReSizeWidth, 400 * windowReSizeHeight, DARKBLUE); //Fondo

	if (player1Win)
		DrawText("YOU WIN", (screenWidth / 2 - 100) * windowReSizeWidth, 50 * windowReSizeWidth, 50 * windowReSizeHeight, BLACK);
	else
		DrawText("GAME OVER", (screenWidth / 2 - 100) * windowReSizeWidth, 50 * windowReSizeWidth, 50 * windowReSizeHeight, BLACK);

	replay->DrawButton(replay->GetRectangle(), "PLAY AGAIN");
	quit->DrawButton(quit->GetRectangle(), "QUIT");
}

void EndGameScreen::Update()
{

}

void EndGameScreen::SetButtonsData()
{
	replay->SetRectanglePos(screenWidth / 2 - 100, screenHeight / 2 - 50);
	quit->SetRectanglePos(screenWidth / 2 - 100, screenHeight / 2 + 50);

	replay->SetHeight(50);
	replay->SetWidth(700);

	quit->SetHeight(50);
	quit->SetWidth(400);
}

void EndGameScreen::SetWinPlayer(bool player1)
{
	player1Win = player1;
}

void EndGameScreen::SetSceneManager(SceneManager* sc)
{
	sceneManager = sc;
}

void EndGameScreen::InitEndGameScreenData()
{
	SetButtonsData();
}
