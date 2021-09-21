#include "BigMeteor.h"

BigMeteor::BigMeteor()
{
	active = false;
	color = DARKBLUE;
	position = { 0,0 };
	radius = 40;
	speed = { 0,0 };
}

BigMeteor::~BigMeteor()
{

}

Vector2 BigMeteor::GetSpeed()
{
	return speed;
}

Vector2 BigMeteor::GetPosition()
{
	return position;
}

float BigMeteor::GetRadius()
{
	return radius;
}

Color BigMeteor::GetColor()
{
	return color;
}

bool BigMeteor::GetActive()
{
	return active;
}

void BigMeteor::SetSpeed(Vector2 _speed)
{
	speed = _speed;
}

void BigMeteor::SetPosition(Vector2 _position)
{
	position = _position;
}

void BigMeteor::SetRadius(float _radius)
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;

	radius = _radius * windowReSizeWidth;
}

void BigMeteor::SetActive(bool _active)
{
	active = _active;
}

void BigMeteor::SetColor(Color _color)
{
	color = _color;
}

void BigMeteor::Draw()
{
	if (active)
		DrawCircleV(position, radius, DARKGRAY);
	else
		DrawCircleV(position, radius, Fade(LIGHTGRAY, 0.3f));
}

void BigMeteor::Update()
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenWidth() / screenHeight;

	if (active)
	{
		position.x += speed.x * 100 * GetFrameTime();
		position.y += speed.y * 100 * GetFrameTime();

		if (position.x > (GetScreenWidth() + radius))
			position.x = -(radius);
		else if (position.x < 0 - radius) 
			position.x = GetScreenWidth() + radius;
		if (position.y > GetScreenHeight() + radius)
			position.y = -(radius);
		else if (position.y < 0 - radius)
			position.y = GetScreenHeight() + radius;
	}

	
}
