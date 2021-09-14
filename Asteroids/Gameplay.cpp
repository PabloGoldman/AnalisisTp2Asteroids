#include "Gameplay.h"
#include <iostream>
#include <string>

const int screenWidth = 800;
const int screenHeight = 450;
const int fontSize = 40;
const int pointsToWin = 10;

Gameplay::Gameplay()
{
	player = new Player();
	hud = new HUD();
	pause = new InGamePause();

	inPause = false;
}

Gameplay::~Gameplay()
{
	delete player;
	delete hud;
	delete pause;
}

void Gameplay::InGame()
{
	Input();
	if (!pause->GetInPause())
	{
		Update();
	}
	else
	{
		pause->InPause();
		if (scene->GetScene() == Scene::MENU)
		{
			ResetData(player);
		}
	}
	audioManager->PlayGameMusic();
	Draw();
}

bool Gameplay::GetInPause()
{
	return inPause;
}

void Gameplay::SetInPause(bool pause)
{
	inPause = pause;
}

void Gameplay::Input()
{
	if (IsKeyReleased(KEY_P))
	{
		pause->SetInPause(!pause->GetInPause());
	}
}

void Gameplay::Update()
{
	MovePlayer();
}

void Gameplay::Draw()
{
	player->DrawPlayer();

	DrawPlayerPoints(player, 300, 50);
}


void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::MovePlayer()
{
	RotatePlayer();
	SpeedMovement();
	Accelerate();
	Move();
}

void Gameplay::RotatePlayer()
{
	if (IsKeyDown(KEY_LEFT))
		player->AddRotation(-200 * GetFrameTime());
	if (IsKeyDown(KEY_RIGHT)) 
		player->AddRotation(200 * GetFrameTime());
}

void Gameplay::Move()
{
	player->AddPosition({ player->GetSpeed().x * player->GetAcceleration() * GetFrameTime(),
		player->GetSpeed().y * player->GetAcceleration()* GetFrameTime() });
}

void Gameplay::SpeedMovement()
{
	player->SetSpeed({ {sin(player->GetRotation() * DEG2RAD) * 100.0f},
		{cos(player->GetRotation() * DEG2RAD) * 100.0f} });
} 

void Gameplay::Accelerate()
{
	if (IsKeyDown(KEY_UP)) 
	{
		if (player->GetAcceleration() < 1)
			player->AddAcceleration(0.04f);
	}
	else 
	{
		if (player->GetAcceleration() > 0)
			player->AddAcceleration(-0.02f);
		else if (player->GetAcceleration() < 0)
			player->SetAcceleration(0);
	}
	if (IsKeyDown(KEY_DOWN))	
	{
		if (player->GetAcceleration() > 0)
			player->AddAcceleration(-0.04f);
		else if (player->GetAcceleration() < 0)
			player->SetAcceleration(0);
	}
}

void Gameplay::DrawPlayerPoints(Player* player, int x, int y)
{
	hud->DrawPoints(player->GetPoints(), x, y, fontSize, BLACK);
}

void Gameplay::ResetData(Player* player)
{
	ResetPlayerData(player);
}

void Gameplay::ResetPlayerData(Player* player)
{
	player->SetPoints(0);
	player->SetHeight((20.0f / 2) / tanf(20 * DEG2RAD));
	player->SetAcceleration(0);
	player->SetRotation(0);
}

void Gameplay::InitGameplay()
{
	ResetPlayerData(player);
	SetPlayerData(player, { screenWidth / 2, screenHeight / 2 - player->GetHeight() / 2 });

	SetInGamePauseData();

	pause->SetSceneManager(scene);
}

void Gameplay::SetPlayerData(Player* player, Vector2 pos)
{
	SetPlayerPosition(player, pos);
}

void Gameplay::SetPlayerPosition(Player* player, Vector2 pos)
{
	player->SetPlayerPos(pos);
}

void Gameplay::SetEndGameScreen(EndGameScreen* eg)
{
	endGameScreen = eg;
}

void Gameplay::SetInGamePauseData()
{
	pause->InitInPauseData();
	pause->SetSceneManager(scene);
}

void Gameplay::SetAudioManager(AudioManager* am)
{
	audioManager = am;
}




