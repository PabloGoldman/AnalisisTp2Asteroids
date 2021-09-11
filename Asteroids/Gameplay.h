#pragma once
#include "Player.h"
#include "HUD.h"
#include "InGamePause.h"
#include "AudioManager.h"
#include "EndGameScreen.h"

class Gameplay
{
private:

	EndGameScreen* endGameScreen;
	AudioManager* audioManager;
	SceneManager* scene;
	InGamePause* pause;
	HUD* hud;
	Player* player;

	bool inPause;

	void Input();
	void Update();
	void Draw();
	void SetPlayerData(Player* player, int posX, int posY);
	void SetPlayerPosition(Player* player, int posX, int posY);
	void DrawPlayer(Player* player);
	void DrawPlayerPoints(Player* player, int x, int y);
	void ResetPlayerData(Player* player);
	void ResetData(Player* player);

public:
	Gameplay();
	~Gameplay();

	bool GetInPause();

	void SetInPause(bool pause);

	void SetEndGameScreen(EndGameScreen* eg);
	void SetInGamePauseData();
	void SetAudioManager(AudioManager* am);
	void SetSceneManager(SceneManager* sc);
	void InGame();
	void InitGameplay();
};

