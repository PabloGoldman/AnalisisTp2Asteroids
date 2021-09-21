#include "Menu.h"


const int fontSize = 40;

int rectangleWidth = 250;
int rectangleHeight = 250;

int txtSize = 50;

int PlayButtonPosition = 50;
int OptionsButtonPosition = 150;
int CreditsButtonPosition = 250;
int ExitButtonPosition = 350;
int AspectRatioButtonPosition = 150;

int optionButtonHeight = 20;
int optionButtonWidth = 20;

Menu::Menu()
{
	menuScene = MenuScene::PLAY;

	for (int i = 0; i < totalButtons; i++)
		_button[i] = new Button();
}

Menu::~Menu()
{
	for (int i = 0; i < totalButtons; i++)
		delete _button[i];
	UnloadTextures();
}

void Menu::SetAudioManager(AudioManager* am)
{
	audioManager = am;
}

void Menu::SetSceneManager(SceneManager* sm)
{
	sceneManager = sm;
}

void Menu::InMenu()
{
	Input();
	Update();
	Draw();
}

void Menu::Input()
{
	Menu::CheckInput();
}

void Menu::Update()
{
	audioManager->PlayMenuMusic();
	Menu::SetMenuOption();
}

void Menu::Draw()
{
	DrawButton(_button[0], "PLAY");
	DrawButton(_button[1], "CONTROLS");
	DrawButton(_button[2], "CREDITS");
	DrawButton(_button[3], "EXIT");
	DrawButton(_button[4], "RES");

	DrawLogo();
}

void Menu::InitMenuData()
{
	LoadTextures();

	SetButtonsData(_button[0], screenWidth * 0.5 - 100, PlayButtonPosition, 70, 300);
	SetButtonsData(_button[1], screenWidth * 0.5 - 100, OptionsButtonPosition, 70, 300);
	SetButtonsData(_button[2], screenWidth * 0.5 - 100, CreditsButtonPosition, 70, 300);
	SetButtonsData(_button[3], screenWidth * 0.5 - 100, ExitButtonPosition, 70, 300);
	SetButtonsData(_button[4], 30, AspectRatioButtonPosition, 70, 300);
}

void Menu::DrawLogo()
{
	//DrawTextureEx(logo, { screenWidth - 200,screenHeight - 170 }, 0, 0.4, WHITE);
}

void Menu::SetButtonsData(Button _button[], int posX, int posY, int height, int width)
{
	_button->SetRectanglePos(posX, posY);

	_button->SetHeight(height);
	_button->SetWidth(width);

	_button->SetColor(BLACK);
}

void Menu::LoadTextures()
{
	//logo = LoadTexture("res/Images/assets/Cachuflito.png");
}

void Menu::UnloadTextures()
{
	//UnloadTexture(logo);
}

void Menu::DrawButton(Button _button[], const char text[])
{
	_button->DrawButton(_button->GetRectangle(), text);
}

void Menu::CheckInput()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		if (CheckCollisionPointRec(GetMousePosition(), _button[0]->GetRectangle()))
		{
			sceneManager->SetSceneManager(Scene::GAME);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), _button[1]->GetRectangle()))
		{
			sceneManager->SetSceneManager(Scene::RULES);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), _button[2]->GetRectangle()))
		{
			sceneManager->SetSceneManager(Scene::CREDITS);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), _button[3]->GetRectangle()))
		{
			sceneManager->SetSceneManager(Scene::EXIT);
		}
		else if (CheckCollisionPointRec(GetMousePosition(), _button[4]->GetRectangle()))
		{
			if (GetScreenWidth() == 800)
			{
				SetWindowSize(1200, 675);
				InitMenuData();
			}
			else if (GetScreenWidth() == 1200)
			{
				SetWindowSize(1920, 1080);
				InitMenuData();
			}
			else if (GetScreenWidth() == 1920)
			{
				SetWindowSize(800, 450);
				InitMenuData();
			}
		}
	}
	audioManager->PlayOptionSound();
}

void Menu::SetMenuOption()
{
	switch (menuScene)
	{
	case MenuScene::PLAY:
		_button[(int)MenuScene::PLAY]->SetActive(true);
		break;
	case MenuScene::OPTIONS:
		_button[(int)MenuScene::OPTIONS]->SetActive(true);
		break;
	case MenuScene::CREDITS:
		_button[(int)MenuScene::CREDITS]->SetActive(true);
		break;
	case MenuScene::EXIT:
		_button[(int)MenuScene::EXIT]->SetActive(true);
		break;
	default:
		break;
	}
	SetButtonsToFalse();
}

void Menu::SetButtonsToFalse()
{
	for (int i = 0; i < totalButtons; i++)
	{
		if (i != (int)menuScene)
		{
			_button[i]->SetActive(false);
		}
	}
}

