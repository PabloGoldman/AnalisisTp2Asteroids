#include "Bullet.h"


Bullet::Bullet()
{
	active = false;
	color = BLACK;
	lifeSpawn = 0;
	lifeTime = 120;
	position = { 0,0 };
	radius = 2;
	rotation = 0;
	speed = { 0,0 };
}

Bullet::~Bullet()
{

}

Vector2 Bullet::GetPosition()
{
	return position;
}

Vector2 Bullet::GetSpeed()
{
	return speed;
}

float Bullet::GetRadius()
{
	return radius;
}

float Bullet::GetRotation()
{
	return rotation;
}

float Bullet::GetLifeSpawn()
{
	return lifeSpawn;
}

bool Bullet::GetIsActive()
{
	return active;
}

Color Bullet::GetColor()
{
	return color;
}

void Bullet::SetPosition(Vector2 _pos)
{
	position = _pos;
}

void Bullet::SetSpeed(Vector2 _speed)
{
	_speed.x *= 50;
	_speed.y *= 50;
	speed = _speed;
}

void Bullet::SetRadius(float _radius)
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;

	radius = _radius * windowReSizeHeight;
}

void Bullet::SetLifeSpawn(float _lifeSpawn)
{
	lifeSpawn = _lifeSpawn;
}

void Bullet::SetIsActive(bool _active)
{
	active = _active;
}

void Bullet::SetColor(Color _color)
{
	color = _color;
}

void Bullet::SetRotation(float _rotation)
{
	rotation = _rotation;
}

void Bullet::SetLifeTime(float _lifetime)
{
	lifeTime = _lifetime;
}

void Bullet::Update()
{
	LifeTime();
	WallCollision();

	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenHeight() / screenHeight;
}

void Bullet::Draw()
{
	if (active)
	{
		DrawCircleV(position, radius, BLACK);
	}
}

void Bullet::AddPosition(Vector2 pos)
{
	position.x += pos.x * GetFrameTime();
	position.y -= pos.y * GetFrameTime();
}

void Bullet::LifeTime()
{
	if (lifeSpawn >= lifeTime)
	{
		ResetData();
	}
}

void Bullet::WallCollision()
{
	if (position.x > (screenWidth * windowReSizeWidth + radius))
	{
		active = false;
		lifeSpawn = 0;
	}
	else if (position.x < (0 - radius))
	{
		active = false;
		lifeSpawn = 0;
	}
	if (position.y > (screenHeight * windowReSizeHeight + radius))
	{
		active = false;
		lifeSpawn = 0;
	}
	else if (position.y < (0 - radius))
	{
		active = false;
		lifeSpawn = 0;
	}
}

void Bullet::ResetData()
{
	position = { 0, 0 };
	speed = { 0, 0 };
	lifeSpawn = 0;
	active = false;
}

