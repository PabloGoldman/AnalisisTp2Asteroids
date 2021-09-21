#include "SmallMeteor.h"


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
	windowReSizeWidth = GetScreenWidth() / screenWidth;

	radius = _radius * windowReSizeWidth;
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

