#pragma once
#include "Button.h"
#include "SceneManager.h"
#include "AudioManager.h"

enum class MenuScene { PLAY, OPTIONS, CREDITS, EXIT, MENUOPTION };

const int totalButtons = 4;

class Menu
{
private:

	MenuScene menuScene;
	AudioManager* audioManager;
	SceneManager* sceneManager;
	Button* _button[totalButtons];
	Texture2D logo;

	void Input();
	void Update();
	void Draw();
	void SetMenuOption();
	void CheckInput();
	void CheckOptionState();
	void SetButtonsData(Button _button[], int posX, int posY, int height, int width);
	void DrawButton(Button _button[], const char text[]);
	void SetButtonsToFalse();
	void LoadTextures();
	void UnloadTextures();
	void DrawLogo();

public:
	Menu();
	~Menu();
	void InMenu();
	void InitMenuData();
	void SetSceneManager(SceneManager* sm);
	void SetAudioManager(AudioManager* am);
};

