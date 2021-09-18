#pragma once
#include "Player.h"
#include "Bullet.h"
#include "HUD.h"
#include "InGamePause.h"
#include "AudioManager.h"
#include "EndGameScreen.h"
#include "BigMeteor.h"
#include "MediumMeteor.h"
#include "SmallMeteor.h"

class Gameplay
{
private:

	Bullet* bullet[10];
	BigMeteor* bigMeteor[4];
	MediumMeteor* mediumMeteor[8];
	SmallMeteor* smallMeteor[16];

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
	void SetPlayerData(Player* player, Vector2 pos);
	void SetPlayerPosition(Player* player, Vector2 pos);
	void DrawPlayerPoints(Player* player, int x, int y);
	void ResetPlayerData(Player* player);
	void ResetData(Player* player);
	void GameUpdate();
	void RotatePlayer();
	void SetMovSpeed();
	void Accelerate();
	void Move();
	void SetMeteorsData();
	void PlayerMeteorsCollision();
	void MeteorsLogic();
	void BulletMeteorsCollision();

	float Vector2Angle(Vector2 v1, Vector2 v2);

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

