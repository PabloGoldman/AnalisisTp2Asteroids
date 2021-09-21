#include "Gameplay.h"
#include <iostream>
#include <string>
#include <cmath>

const int fontSize = 40;
int totalBullets = 3;
const int bigMeteors = 4;
const int mediumMeteors = 8;
const int smallMeteors = 16;

bool hasPowerUp = false;

int mediumMeteorsCounteds = 0;
int smallMeteorsCounteds = 0;
int destroyedMeteors = 0;

Gameplay::Gameplay()
{
	player = new Player();
	hud = new HUD();
	pause = new InGamePause();
	powerUp = new PowerUp();
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

	for (int i = 0; i < totalBullets; i++)
	{
		player->SetBullets(bullet[i]);
	}

	time = 0;
}

Gameplay::~Gameplay()
{
	delete player;
	delete hud;
	delete pause;
	delete powerUp;

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

void Gameplay::GameUpdate()
{
	player->Update();

	Move();
	PlayerMeteorsCollision();
	BulletMeteorsCollision();
	MeteorsLogic();
	CheckGameState();
	PowerUpCollision();
	ResetPowerUp();

	powerUp->Update();
}

void Gameplay::InGame()
{
	Input();
	if (!pause->GetInPause())
	{
		Update();
		Draw();
	}
	else
	{
		Draw();
		pause->InPause();
		if (scene->GetScene() == Scene::MENU)
		{
			ResetData();
		}
	}
	audioManager->PlayGameMusic();
	
}

bool Gameplay::GetInPause()
{
	return inPause;
}

void Gameplay::ResetPowerUp()
{
	if (powerUp->GetTime() >= 5 && hasPowerUp)
	{
		player->SetHeight((20.0f / 2) / tanf(20 * DEG2RAD));
		for (int i = 0; i < totalBullets; i++)
		{
			bullet[i]->SetLifeTime(60);
		}
		powerUp->SetTime(0);
		hasPowerUp = false;
	}
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
	powerUp->Draw();

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

	DrawPlayerPoints(player, screenWidth / 2 - 20, 50);
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::PowerUpCollision()
{
	if (CheckCollisionCircles({ player->GetCollider().x,player->GetCollider().y },
		player->GetCollider().z, powerUp->GetPosition(), powerUp->GetRadius()) && powerUp->GetActive())
	{
		int aux = GetRandomValue(1, 2);
		if (aux == 1)
		{
			player->SetHeight((20.0f / 4) / tanf(15 * DEG2RAD));
		}
		else
		{
			for (int i = 0; i < totalBullets; i++)
			{
				bullet[i]->SetLifeTime(60);
			}
		}
		powerUp->SetActive(false);
		powerUp->SetTime(0);
		hasPowerUp = true;
	}
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

void Gameplay::CheckGameState()
{
	if (destroyedMeteors == 28 || gameOver)
	{
		if (destroyedMeteors == 28)
			endGameScreen->SetWinPlayer(true);
		else
			endGameScreen->SetWinPlayer(false);

		gameOver = false;
		ResetData();
		scene->SetSceneManager(Scene::ENDGAME);
	}
}

void Gameplay::ResetData()
{
	player->SetPoints(0);
	player->SetHeight((20.0f / 2) / tanf(20 * DEG2RAD));
	player->SetAcceleration({ 0,0 });
	player->SetCollider({ player->GetPos().x + (float)sin(player->GetRotation() * DEG2RAD)
		* (player->GetHeight() / 2.5f), player->GetPos().y - (float)cos(player->GetRotation() * DEG2RAD) * (player->GetHeight() / 2.5f), 12 });
	player->SetRotation(0);
	player->SetPlayerPos({ screenWidth / 2, screenHeight / 2 - player->GetHeight() / 2 });
	SetMeteorsData();
	powerUp->SetActive(false);

	for (int i = 0; i < totalBullets; i++)
	{
		bullet[i]->SetIsActive(false);
	}

	destroyedMeteors = 0;
	mediumMeteorsCounteds = 0;
	smallMeteorsCounteds = 0;
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

void Gameplay::Move()
{
	RotatePlayer();

	if (IsMouseButtonDown(MOUSE_RIGHT_BUTTON)) 
	{
		Accelerate();
	}

	player->AddPosition({ player->GetAcceleration().x * GetFrameTime(),
		player->GetAcceleration().y * GetFrameTime()});

	player->WallCollision();
}

void Gameplay::PlayerMeteorsCollision()
{
	player->SetCollider({ player->GetPos().x + (float)sin(player->GetRotation() * DEG2RAD)
		* (player->GetHeight() / 2.5f), player->GetPos().y - (float)cos(player->GetRotation() * DEG2RAD) * (player->GetHeight() / 2.5f), 20 });
	for (int i = 0; i < bigMeteors; i++)
	{
		if (CheckCollisionCircles({ player->GetCollider().x,player->GetCollider().y },
			player->GetCollider().z, bigMeteor[i]->GetPosition(), bigMeteor[i]->GetRadius()) && bigMeteor[i]->GetActive())
		{
			gameOver = true;
		}
	}
	for (int i = 0; i < mediumMeteors; i++)
	{
		if (CheckCollisionCircles({ player->GetCollider().x,player->GetCollider().y },
			player->GetCollider().z, mediumMeteor[i]->GetPosition(), mediumMeteor[i]->GetRadius()) && mediumMeteor[i]->GetActive())
		{
			gameOver = true;
		}
	}
	for (int i = 0; i < smallMeteors; i++)
	{
		if (CheckCollisionCircles({ player->GetCollider().x,player->GetCollider().y },
			player->GetCollider().z, smallMeteor[i]->GetPosition(), smallMeteor[i]->GetRadius()) && smallMeteor[i]->GetActive())
		{
			gameOver = true;
		}
	}
	time = 0;
}

void Gameplay::RotatePlayer()
{
	player->SetRotation(Vector2Angle(player->GetPos(), GetMousePosition()) + 90);
}

void Gameplay::SetMovSpeed()
{
	
}

void Gameplay::Accelerate()
{
	player->AddAcceleration(-(Direction().x / (sqrt((Direction().x * Direction().x) + Direction().y * Direction().y))),
		-(Direction().y / (sqrt((Direction().x * Direction().x) + Direction().y * Direction().y))));
}

void Gameplay::DrawPlayerPoints(Player* player, int x, int y)
{
	hud->DrawPoints(player->GetPoints(), x, y, fontSize, BLACK);
}

void Gameplay::InitGameplay()
{
	ResetData();

	SetInGamePauseData();

	pause->SetSceneManager(scene);
}

void Gameplay::SetMeteorsData()
{
	for (int i = 0; i < bigMeteors; i++)
	{
		do
		{
			bigMeteor[i]->SetPosition({ (float)GetRandomValue(0, GetScreenWidth()),(float)GetRandomValue(0, GetScreenHeight()) });
		} while (bigMeteor[i]->GetPosition().x - player->GetPos().x  < 10 && bigMeteor[i]->GetPosition().x - player->GetPos().x > -10);

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

float Gameplay::Vector2Angle(Vector2 v1, Vector2 v2)
{
	float result = atan2f(v2.y - v1.y, v2.x - v1.x) * RAD2DEG;
	if (result < 0)
		result += 360;

	return result;
}

Vector2 Gameplay::Direction()
{
	return { GetMousePosition().x - player->GetPos().x ,GetMousePosition().y - player->GetPos().y };
}

float Gameplay::Lenght(Vector2 v)
{
	return sqrtf((v.x * v.x) + (v.y * v.y));
}






