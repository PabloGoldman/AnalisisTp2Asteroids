#include "Bullet.h"

const int screenWidth = 800;
const int screenHeight = 450;

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

int Bullet::GetLifeSpawn()
{
	return lifeSpawn;
}

bool Bullet::GetIsActive()
{
	return false;
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
	speed = _speed;
}

void Bullet::SetRadius(float _radius)
{
	radius = _radius;
}

void Bullet::SetLifeSpawn(int _lifeSpawn)
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

void Bullet::Update()
{
	Movement();
	LifeTime();
	WallCollision();
	ResetData();
}

void Bullet::Movement()
{
	position.x += speed.x;
	position.y += speed.y;
}

void Bullet::LifeTime()
{
	if (active)
		lifeSpawn++;
}

void Bullet::WallCollision()
{
	if (position.x > screenWidth + radius) 
	{
		active = false;
		lifeSpawn = 0;
	}
	else if (position.x < 0 - radius) 
	{
		active = false;
		lifeSpawn = 0;
	}
	if (position.y > screenHeight + radius) 
	{
		active = false;
		lifeSpawn = 0;
	}
	else if (position.y < 0 - radius) 
	{
		active = false;
		lifeSpawn = 0;
	}
}

void Bullet::ResetData()
{
	if (lifeSpawn >= 60)
	{
		position = { 0, 0 };
		speed = { 0, 0 };
		lifeSpawn = 0;
		active = false;
	}
}

void Bullet::Draw()
{
	if (active) 
		DrawCircleV(position, radius, BLACK);
}
