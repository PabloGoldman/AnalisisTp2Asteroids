#include "MediumMeteor.h"

MediumMeteor::MediumMeteor()
{
	active = false;
	color = DARKBLUE;
	position = { 0,0 };
	radius = 40;
	speed = { 0,0 };
}

MediumMeteor::~MediumMeteor()
{
}

Vector2 MediumMeteor::GetSpeed()
{
	return speed;
}

Vector2 MediumMeteor::GetPosition()
{
	return position;
}

float MediumMeteor::GetRadius()
{
	return radius;
}

Color MediumMeteor::GetColor()
{
	return color;
}

bool MediumMeteor::GetActive()
{
	return active;
}

void MediumMeteor::SetSpeed(Vector2 _speed)
{
	speed = _speed;
}

void MediumMeteor::SetPosition(Vector2 _position)
{
	position = _position;
}

void MediumMeteor::SetRadius(float _radius)
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;

	radius = _radius * windowReSizeWidth;
}

void MediumMeteor::SetActive(bool _active)
{
	active = _active;
}

void MediumMeteor::SetColor(Color _color)
{
	color = _color;
}

void MediumMeteor::Draw()
{
	if (active)
		DrawCircleV(position, radius, DARKGRAY);
	else
		DrawCircleV(position, radius, Fade(LIGHTGRAY, 0.3f));
}

void MediumMeteor::Update()
{
	windowReSizeWidth = GetScreenWidth() / screenWidth;
	windowReSizeHeight = GetScreenWidth() / screenHeight;

	if (active)
	{
		position.x += speed.x * 100 * GetFrameTime();
		position.y += speed.y * 100 * GetFrameTime();

		if (position.x > (screenWidth * windowReSizeWidth + radius))
			position.x = -(radius);
		else if (position.x < 0 - radius)
			position.x = screenWidth * windowReSizeWidth + radius;
		if (position.y > screenHeight * windowReSizeHeight + radius)
			position.y = -(radius);
		else if (position.y < 0 - radius)
			position.y = screenHeight * windowReSizeHeight + radius;
	}
	
}


