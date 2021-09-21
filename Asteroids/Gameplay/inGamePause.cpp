#include "InGamePause.h"

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
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), resume->GetRectangle()))
		{
			SetInPause(false);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), quit->GetRectangle()))
		{
			SetInPause(false);
			sceneManager->SetSceneManager(Scene::MENU);
		}
	}
}

void InGamePause::DrawPauseMenu()
{
	float windowReSizeWidth = GetScreenWidth() / screenWidth;
	float windowReSizeHeight = GetScreenHeight() / screenHeight;

	Font font = GetFontDefault();

	//DrawRectangle((screenWidth / 2 - 250) * windowReSizeWidth, (screenHeight / 2 - 100) * windowReSizeHeight, 500 * windowReSizeWidth, 300 * windowReSizeHeight, DARKBLUE);
	resume->DrawButton(resume->GetRectangle(), "RESUME");
	quit->DrawButton(quit->GetRectangle(), "QUIT");
}

void InGamePause::Update()
{

}

void InGamePause::SetButtonsData()
{
	resume->SetRectanglePos(screenWidth / 2 - 80, screenHeight / 2 - 40);
	quit->SetRectanglePos(screenWidth / 2 - 80, screenHeight / 2 + 10);

	quit->SetHeight(50);
	quit->SetWidth(400);

	resume->SetHeight(50);
	resume->SetWidth(400);
}

void InGamePause::InitInPauseData()
{
	SetButtonsData();
}
