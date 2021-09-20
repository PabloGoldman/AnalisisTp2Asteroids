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
#include "PowerUp.h"

class Gameplay
{
private:

	Bullet* bullet[4];
	BigMeteor* bigMeteor[4];
	MediumMeteor* mediumMeteor[8];
	SmallMeteor* smallMeteor[16];
	PowerUp* powerUp;

	EndGameScreen* endGameScreen;
	AudioManager* audioManager;
	SceneManager* scene;
	InGamePause* pause;
	HUD* hud;
	Player* player;

	bool inPause;
	bool gameOver;
	float time;

	void Input();
	void Update();
	void Draw();
	void SetPlayerPosition(Player* player, Vector2 pos);
	void DrawPlayerPoints(Player* player, int x, int y);
	void ResetData();
	void GameUpdate();
	void RotatePlayer();
	void SetMovSpeed();
	void Accelerate();
	void Move();
	void SetMeteorsData();
	void PlayerMeteorsCollision();
	void MeteorsLogic();
	void BulletMeteorsCollision();
	void CheckGameState();
	void PowerUpCollision();
	void ResetPowerUp();

	float Vector2Angle(Vector2 v1, Vector2 v2);
	Vector2 Direction();
	float Lenght(Vector2 v);

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

