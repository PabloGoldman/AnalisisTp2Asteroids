#include "Gameplay.h"
#include <iostream>
#include <string>

const int screenWidth = 800;
const int screenHeight = 450;
const int fontSize = 40;
const int totalBullets = 10;
const int bigMeteors = 4;
const int mediumMeteors = 8;
const int smallMeteors = 16;

int mediumMeteorsCounteds = 0;
int smallMeteorsCounteds = 0;
int destroyedMeteors = 0;

Gameplay::Gameplay()
{
	player = new Player();
	hud = new HUD();
	pause = new InGamePause();
	inPause = false;

	for (int i = 0; i < bigMeteors; i++)
	{
		bigMeteor[i] = new BigMeteor();
	}
	for (int i = 0; i < mediumMeteors; i++)
	{
		mediumMeteor[i] = new MediumMeteor();
	}
	for (int i = 0; i < smallMeteors; i++)
	{
		smallMeteor[i] = new SmallMeteor();
	}

	for (int i = 0; i < totalBullets; i++)
	{
		bullet[i] = new Bullet();
	}
}

Gameplay::~Gameplay()
{
	delete player;
	delete hud;
	delete pause;

	for (int i = 0; i < bigMeteors; i++)
	{
		delete bigMeteor[i];
	}
	for (int i = 0; i < mediumMeteors; i++)
	{
		delete mediumMeteor[i];
	}
	for (int i = 0; i < smallMeteors; i++)
	{
		delete smallMeteor[i];
	}

	for (int i = 0; i < totalBullets; i++)
	{
		delete bullet[i];
	}
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
			ResetPlayerData(player);
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
	GameUpdate();
}

void Gameplay::Draw()
{
	player->Draw();

	for (int i = 0; i < bigMeteors; i++)
	{
		bigMeteor[i]->Draw();
	}
	for (int i = 0; i < mediumMeteors; i++)
	{
		mediumMeteor[i]->Draw();
	}
	for (int i = 0; i < smallMeteors; i++)
	{
		smallMeteor[i]->Draw();
	}

	DrawPlayerPoints(player, 300, 50);
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::GameUpdate()
{
	player->Update();
	RotatePlayer();
	SetMovSpeed();
	Accelerate();
	Move();
	PlayerMeteorsCollision();
	BulletMeteorsCollision();
	MeteorsLogic();
	CheckWin();
}

void Gameplay::BulletMeteorsCollision()
{
	for (int i = 0; i < totalBullets; i++)
	{
		if (bullet[i]->GetIsActive())
		{
			for (int k = 0; k < bigMeteors; k++)
			{
				if (bigMeteor[k]->GetActive() && CheckCollisionCircles(bullet[i]->GetPosition(), bullet[i]->GetRadius(), bigMeteor[k]->GetPosition(), bigMeteor[k]->GetRadius()))
				{
					bullet[i]->SetIsActive(false);
					bullet[i]->SetLifeSpawn(0);
					bigMeteor[k]->SetActive(false);
					player->AddPoints(1);
					destroyedMeteors++;

					for (int j = 0; j < 2; j++)
					{
						mediumMeteor[mediumMeteorsCounteds]->SetPosition(bigMeteor[k]->GetPosition());

						if (mediumMeteorsCounteds % 2 == 0)
						{
							mediumMeteor[mediumMeteorsCounteds]->SetSpeed({ (float)cos(bullet[i]->GetRotation() * DEG2RAD * 2 * -1), (float)sin(bullet[i]->GetRotation() * DEG2RAD * 2 * -1) });
						}
						else
						{
							mediumMeteor[mediumMeteorsCounteds]->SetSpeed({ (float)cos(bullet[i]->GetRotation() * DEG2RAD * 2), (float)sin(bullet[i]->GetRotation() * DEG2RAD * 2) });
						}
						mediumMeteor[mediumMeteorsCounteds]->SetActive(true);
						mediumMeteorsCounteds++;
					}
					bigMeteor[k]->SetColor(RED);
					k = bigMeteors;
				}

				for (int k = 0; k < mediumMeteors; k++)
				{
					if (mediumMeteor[k]->GetActive() && CheckCollisionCircles(bullet[i]->GetPosition(), bullet[i]->GetRadius(), mediumMeteor[k]->GetPosition(), mediumMeteor[k]->GetRadius()))
					{
						bullet[i]->SetIsActive(false);
						bullet[i]->SetLifeSpawn(0);
						mediumMeteor[k]->SetActive(false);
						player->AddPoints(1);
						destroyedMeteors++;

						for (int j = 0; j < 2; j++)
						{
							smallMeteor[smallMeteorsCounteds]->SetPosition(mediumMeteor[k]->GetPosition());

							if (smallMeteorsCounteds % 2 == 0)
							{
								smallMeteor[smallMeteorsCounteds]->SetSpeed({ (float)cos(bullet[i]->GetRotation() * DEG2RAD * 2 * -1), (float)sin(bullet[i]->GetRotation() * DEG2RAD * 2 * -1) });
							}
							else
							{
								smallMeteor[smallMeteorsCounteds]->SetSpeed({ (float)cos(bullet[i]->GetRotation() * DEG2RAD * 2), (float)sin(bullet[i]->GetRotation() * DEG2RAD * 2) });
							}
							smallMeteor[smallMeteorsCounteds]->SetActive(true);
							smallMeteorsCounteds++;
						}
						mediumMeteor[k]->SetColor(GREEN);
						k = mediumMeteors;
					}
				}
				for (int k = 0; k < smallMeteors; k++)
				{
					if (smallMeteor[k]->GetActive() && CheckCollisionCircles(bullet[i]->GetPosition(), bullet[i]->GetRadius(), smallMeteor[k]->GetPosition(), smallMeteor[k]->GetRadius()))
					{
						bullet[i]->SetIsActive(false);
						bullet[i]->SetLifeSpawn(0);
						smallMeteor[k]->SetActive(false);
						player->AddPoints(1);
						destroyedMeteors++;
						k = smallMeteors;
					}
				}
			}
		}
	}

	
}

void Gameplay::CheckWin() 
{
	if (destroyedMeteors == 28)
		scene->SetSceneManager(Scene::ENDGAME);
}

void Gameplay::MeteorsLogic()
{
	for (int i = 0; i < bigMeteors; i++)
	{
		bigMeteor[i]->Update();
	}
	for (int i = 0; i < mediumMeteors; i++)
	{
		mediumMeteor[i]->Update();
	}
	for (int i = 0; i < smallMeteors; i++)
	{
		smallMeteor[i]->Update();
	}
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

void Gameplay::PlayerMeteorsCollision()
{
	for (int i = 0; i < bigMeteors; i++)
	{
		if (CheckCollisionCircles({player->GetCollider().x,player->GetCollider().y},
		player->GetCollider().z,bigMeteor[i]->GetPosition(), bigMeteor[i]->GetRadius()) && bigMeteor[i]->GetActive())
		{
			//scene->SetSceneManager(Scene::ENDGAME);
		}
	}
	for (int i = 0; i < mediumMeteors; i++)
	{
		if (CheckCollisionCircles({ player->GetCollider().x,player->GetCollider().y },
			player->GetCollider().z, mediumMeteor[i]->GetPosition(), mediumMeteor[i]->GetRadius()) && mediumMeteor[i]->GetActive())
		{
			scene->SetSceneManager(Scene::ENDGAME);
		}
	}
	for (int i = 0; i < smallMeteors; i++)
	{
		if (CheckCollisionCircles({ player->GetCollider().x,player->GetCollider().y },
			player->GetCollider().z, smallMeteor[i]->GetPosition(), smallMeteor[i]->GetRadius()) && smallMeteor[i]->GetActive())
		{
			scene->SetSceneManager(Scene::ENDGAME);
		}
	}
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
		if (player->GetAcceleration() < 10)
			player->AddAcceleration(0.0008f);
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

void Gameplay::ResetPlayerData(Player* player)
{
	ResetData(player);
}

void Gameplay::ResetData(Player* player)
{
	player->SetPoints(0);
	player->SetHeight((20.0f / 2) / tanf(20 * DEG2RAD));
	player->SetAcceleration(0);
	player->SetCollider({ player->GetPos().x + (float)sin(player->GetRotation() * DEG2RAD)
		* (player->GetHeight() / 2.5f), player->GetPos().y - (float)cos(player->GetRotation() * DEG2RAD) * (player->GetHeight() / 2.5f), 12 });
	player->SetRotation(0);
}

void Gameplay::InitGameplay()
{
	ResetPlayerData(player);
	SetPlayerData(player, { screenWidth / 2, screenHeight / 2 - player->GetHeight() / 2 });

	SetMeteorsData();

	SetInGamePauseData();

	pause->SetSceneManager(scene);
}

void Gameplay::SetMeteorsData()
{
	for (int i = 0; i < bigMeteors; i++)
	{
		bigMeteor[i]->SetPosition({ (float)GetRandomValue(0, screenWidth),(float)GetRandomValue(0, screenHeight) });
		bigMeteor[i]->SetSpeed({ (float)GetRandomValue(-2, 2) ,(float)GetRandomValue(-2, 2) });
		bigMeteor[i]->SetActive(true);
		bigMeteor[i]->SetRadius(40);
	}
	for (int i = 0; i < mediumMeteors; i++)
	{
		mediumMeteor[i]->SetPosition({ -100,100 });
		mediumMeteor[i]->SetSpeed({ 0,0 });
		mediumMeteor[i]->SetRadius(20);
		mediumMeteor[i]->SetActive(false);
	}
	for (int i = 0; i < smallMeteors; i++)
	{
		smallMeteor[i]->SetPosition({ -100,100 });
		smallMeteor[i]->SetSpeed({ 0,0 });
		smallMeteor[i]->SetRadius(10);
		smallMeteor[i]->SetActive(false);
	}
}

void Gameplay::SetPlayerData(Player* player, Vector2 pos)
{
	SetPlayerPosition(player, pos);
	player->SetCollider({ player->GetPos().x + (float)sin(player->GetRotation() * DEG2RAD)
		* (player->GetHeight() / 2.5f), player->GetPos().y - (float)cos(player->GetRotation() * DEG2RAD) * (player->GetHeight() / 2.5f), 12 });

	for (int i = 0; i < totalBullets; i++)
	{
		player->SetBullets(bullet[i]);
	}
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




