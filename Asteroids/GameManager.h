#pragma once
#include "Menu.h"
#include "SceneManager.h"
#include "Gameplay.h"
#include "Credits.h"
#include "Rules.h"
#include "InGamePause.h"
#include "EndGameScreen.h"
#include "AudioManager.h"

class GameManager
{
private:
	int screenWidth;
	int screenHeight;
	int fontSize;

	AudioManager* _audioManager;
	EndGameScreen* _endGameScreen;
	Rules* _rules;
	Credits* _credits;
	SceneManager* _sceneManager;
	Menu* _menu;
	Gameplay* _gameplay;

	bool isPlaying;
	bool rulesInited;
	bool gameplayInited;
	bool menuInited;
	bool creditsInited;
	bool modeScreenInited;
	bool endGameScreenInited;

public:
	GameManager();
	~GameManager();

	void RunGame();
	void InitAllGameData();
	void InitAllMenuData();
	void InitAllCreditsData();
	void InitAllChooseModeData();
	void InitAllRulesData();
	void InitAllEndGameScreenData();
	void PlayMusicInMenu();
};

