#include "SmallMeteor.h"
const int screenWidth = 800;
const int screenHeight = 450;

SmallMeteor::SmallMeteor()
{
	active = false;
	color = DARKBLUE;
	position = { 0,0 };
	radius = 40;
	speed = { 0,0 };
}

SmallMeteor::~SmallMeteor()
{
}

Vector2 SmallMeteor::GetSpeed()
{
	return speed;
}

Vector2 SmallMeteor::GetPosition()
{
	return position;
}

float SmallMeteor::GetRadius()
{
	return radius;
}

Color SmallMeteor::GetColor()
{
	return color;
}

bool SmallMeteor::GetActive()
{
	return active;
}

void SmallMeteor::SetColor(Color _color)
{
	color = _color;
}

void SmallMeteor::SetSpeed(Vector2 _speed)
{
	speed = _speed;
}

void SmallMeteor::SetPosition(Vector2 _position)
{
	position = _position;
}

void SmallMeteor::SetRadius(float _radius)
{
	radius = _radius;
}

void SmallMeteor::SetActive(bool _active)
{
	active = _active;
}

void SmallMeteor::Draw()
{
	if (active)
		DrawCircleV(position, radius, DARKGRAY);
	else
		DrawCircleV(position, radius, Fade(LIGHTGRAY, 0.3f));
}

void SmallMeteor::Update()
{
	if (active)
	{
		position.x += speed.x * 100 * GetFrameTime();
		position.y += speed.y * 100 * GetFrameTime();

		if (position.x > screenWidth + radius)
			position.x = -(radius);
		else if (position.x < 0 - radius)
			position.x = screenWidth + radius;
		if (position.y > screenHeight + radius)
			position.y = -(radius);
		else if (position.y < 0 - radius)
			position.y = screenHeight + radius;
	}
}

