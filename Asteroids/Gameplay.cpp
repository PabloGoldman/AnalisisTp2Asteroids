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
	PlayerLogic();
}

void Gameplay::Draw()
{
	player->Draw();

	DrawPlayerPoints(player, 300, 50);
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::PlayerLogic()
{
	player->Update();
	RotatePlayer();
	SetMovSpeed();
	Accelerate();
	Move();
}

void Gameplay::RotatePlayer()
{
	player->SetRotation(Vector2Angle(player->GetPos(), GetMousePosition()) + 90);
}

void Gameplay::Move()
{
	player->AddPosition({ player->GetSpeed().x * player->GetAcceleration() * GetFrameTime(),
		player->GetSpeed().y * -player->GetAcceleration() * GetFrameTime() });
	player->WallCollision();
}

float Gameplay::Vector2Angle(Vector2 v1, Vector2 v2)
{
	float result = atan2f(v2.y - v1.y, v2.x - v1.x) * RAD2DEG;
	if (result < 0)
		result += 360;

	return result;
}

void Gameplay::SetMovSpeed()
{
	player->SetSpeed({ {sin(player->GetRotation() * DEG2RAD) * 100.0f},
		{cos(player->GetRotation() * DEG2RAD) * 100.0f} });
}

void Gameplay::Accelerate()
{
	if (IsMouseButtonDown(1))
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
	player->SetCollider({ player->GetPos().x + (float)sin(player->GetRotation() * DEG2RAD)
		* (player->GetHeight() / 2.5f), player->GetPos().y - (float)cos(player->GetRotation() * DEG2RAD) * (player->GetHeight() / 2.5f), 12 });
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




