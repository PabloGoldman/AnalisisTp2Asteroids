#include "EndGameScreen.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

EndGameScreen::EndGameScreen()
{
	gameFinished = new Button();
	replay = new Button();
	quit = new Button();

	player1Win = false;
}

EndGameScreen::~EndGameScreen()
{
	delete replay;
	delete quit;
	delete gameFinished;
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
	if (IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_S) || IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_W))
	{
		if (option == ENDGAMEOPTION::PLAY)
			option = ENDGAMEOPTION::QUIT;
		else
			option = ENDGAMEOPTION::PLAY;
	}
	else if (IsKeyReleased(KEY_ENTER))
	{
		if (option == ENDGAMEOPTION::PLAY)
			sceneManager->SetSceneManager(Scene::GAME);

		else
			sceneManager->SetSceneManager(Scene::MENU);
	}
}

void EndGameScreen::DrawEndGameScreen()
{
	Font font = GetFontDefault();

	DrawRectangle(screenWidth / 2 - 220, 20, 500, 400, DARKBLUE); //Fondo

	if (player1Win)
		gameFinished->DrawButton(gameFinished->GetRectangle(), "PLAYER 1 WINS");
	else
		gameFinished->DrawButton(gameFinished->GetRectangle(), "PLAYER 2 WINS");


	replay->DrawButton(replay->GetRectangle(), "PLAY AGAIN");
	quit->DrawButton(quit->GetRectangle(), "QUIT");
}

void EndGameScreen::Update()
{
	switch (option)
	{
	case ENDGAMEOPTION::PLAY:
		replay->SetActive(true);
		quit->SetActive(false);
		break;
	case ENDGAMEOPTION::QUIT:
		replay->SetActive(false);
		quit->SetActive(true);
		break;
	default:
		break;
	}
}

void EndGameScreen::SetButtonsData()
{
	gameFinished->SetRectanglePos(screenWidth / 2 - 160, 50);
	replay->SetRectanglePos(screenWidth / 2 - 100, screenHeight / 2 - 50);
	quit->SetRectanglePos(screenWidth / 2 - 100, screenHeight / 2 + 50);

	gameFinished->SetHeight(400);
	gameFinished->SetWidth(700);

	replay->SetHeight(400);
	replay->SetWidth(700);

	quit->SetHeight(400);
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
