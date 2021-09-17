#include "Player.h"
#include <math.h>

const int screenWidth = 800;
const int screenHeight = 450;
const int totalBullets = 10;

Player::Player()
{
	color = MAROON;
	speed = { 0,0 };
	points = 0;
	acceleration = 0;
	height = 0;
	collider = { 0,0,0 };
	position = { 0,0 };
	rotation = 0;

	for (int i = 0; i < totalBullets; i++)
	{
		bullet[i] = new Bullet();
	}
}

Player::~Player()
{
	for (int i = 0; i < totalBullets; i++)
	{
		delete bullet[i];
	}
}

Color Player::GetColor()
{
	return color;
}

Vector2 Player::GetSpeed()
{
	return speed;
}

Vector2 Player::GetPos()
{
	return position;
}

int Player::GetPoints()
{
	return points;
}

float Player::GetAcceleration()
{
	return acceleration;
}

float Player::GetRotation()
{
	return rotation;
}

float Player::GetHeight()
{
	return height;
}

void Player::AddPosition(Vector2 _pos)
{
	position.x += _pos.x;
	position.y += _pos.y;
}

void Player::AddRotation(float _rotation)
{
	rotation += _rotation;
}

void Player::AddAcceleration(float _acceleration)
{
	acceleration += _acceleration;
}

void Player::SetAcceleration(float _acceleration)
{
	acceleration = _acceleration;
}

void Player::SetRotation(float _rotation)
{
	rotation = _rotation;
}

void Player::SetSpeed(Vector2 _speed)
{
	speed = _speed;
}

void Player::SetColor(Color _color)
{
	color = _color;
}

void Player::SetHeight(int _height)
{
	height = _height;
}

void Player::SetPoints(int _points)
{
	points = _points;
}

void Player::SetPlayerPos(Vector2 _pos)
{
	position = _pos;
}

void Player::AddPoints(int _points)
{
	points += _points;
}

void Player::Draw()
{
	//Matematica sacada de raylib
	Vector2 v1 = { position.x + sinf(rotation * DEG2RAD) * (height),position.y - cosf(rotation * DEG2RAD) * (height) };
	Vector2 v2 = { position.x - cosf(rotation * DEG2RAD) * (20.0f / 2),position.y - sinf(rotation * DEG2RAD) * (20.0f / 2) };
	Vector2 v3 = { position.x + cosf(rotation * DEG2RAD) * (20.0f / 2),position.y + sinf(rotation * DEG2RAD) * (20.0f / 2) };
	DrawTriangle(v1, v2, v3, color);

	for (int i = 0; i < totalBullets; i++)
	{
		bullet[i]->Draw();
	}
}

void Player::WallCollision()
{
	if (position.x > screenWidth + height)
		position.x = -(height);
	else if (position.x < -(height))
		position.x = screenWidth + height;
	if (position.y > (screenHeight + height))
		position.y = -(height);
	else if (position.y < -(height))
		position.y = screenHeight + height;
}

void Player::Shoot()
{
	for (int i = 0; i < totalBullets; i++)
	{
		if (!bullet[i]->GetIsActive()) {
			bullet[i]->SetPosition({ position.x + (float)sin(rotation * DEG2RAD) * (height), position.y - (float)cos(rotation * DEG2RAD) * (height) });
			bullet[i]->SetIsActive(true);
			bullet[i]->SetSpeed({ (float)(1.5 * sin(rotation * DEG2RAD) * 6.0f), (float)(1.5 * cos(rotation * DEG2RAD) * 6.0f) });
			bullet[i]->SetRotation(rotation);
			break;
		}
	}
}

void Player::Update()
{
	if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
	{
		Shoot();
	}
	for (int i = 0; i < totalBullets; i++)
	{
		bullet[i]->Update();
		bullet[i]->AddPosition({ bullet[i]->GetSpeed().x, bullet[i]->GetSpeed().y });
		if (bullet[i]->GetLifeSpawn() >= 60)
		{
			bullet[i]->ResetData();
		}
	}
}
