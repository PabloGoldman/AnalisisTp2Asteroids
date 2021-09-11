#include "InGamePause.h"

const int screenWidth = 800;
const int screenHeight = 450;

const int fontSize = 40;

InGamePause::InGamePause()
{
	resume = new Button();
	quit = new Button();
}

InGamePause::~InGamePause()
{
	delete resume;
	delete quit;
}

OPTION InGamePause::GetMenuOption()
{
	return option;
}

bool InGamePause::GetInPause()
{
	return inPause;
}

void InGamePause::SetInPause(bool _inPause)
{
	inPause = _inPause;
}

void InGamePause::SetSceneManager(SceneManager* sc)
{
	sceneManager = sc;
}

void InGamePause::InPause()
{
	CheckInput();
	Update();
	DrawPauseMenu();
}

void InGamePause::SetMenuOption(OPTION _option)
{
	option = _option;
}

void InGamePause::CheckInput()
{
	if (IsKeyReleased(KEY_DOWN) || IsKeyReleased(KEY_S) || IsKeyReleased(KEY_UP) || IsKeyReleased(KEY_W))
	{
		if (option == OPTION::RESUME)
			option = OPTION::QUIT;
		else
			option = OPTION::RESUME;
	}
	else if (IsKeyReleased(KEY_ENTER))
	{
		if (option == OPTION::RESUME)
			SetInPause(false);
		else
		{
			SetInPause(false);
			SetMenuOption(OPTION::RESUME);
			sceneManager->SetSceneManager(Scene::MENU);
		}
	}
}

void InGamePause::DrawPauseMenu()
{
	Font font = GetFontDefault();

	DrawRectangle(screenWidth / 2 - 250, screenHeight / 2 - 100, 500, 300, DARKBLUE);
	resume->DrawButton(resume->GetRectangle(), "RESUME");
	quit->DrawButton(resume->GetRectangle(), "QUIT");
}

void InGamePause::Update()
{
	switch (option)
	{
	case OPTION::RESUME:
		resume->SetActive(true);
		quit->SetActive(false);
		break;
	case OPTION::QUIT:
		resume->SetActive(false);
		quit->SetActive(true);
		break;
	default:
		break;
	}
}

void InGamePause::SetButtonsData()
{
	resume->SetRectanglePos(screenWidth / 2 - 80, screenHeight / 2 - 10);
	quit->SetRectanglePos(screenWidth / 2 - 80, screenHeight / 2 + 50);

	quit->SetHeight(400);
	quit->SetWidth(400);

	resume->SetHeight(400);
	resume->SetWidth(400);
}

void InGamePause::InitInPauseData()
{
	SetButtonsData();
}
