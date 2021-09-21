#include "PowerUp.h"

PowerUp::PowerUp()
{
	active = false;
	color = YELLOW;
	position = { -100,100 };
	radius = 20;
	time = 0;
}

PowerUp::~PowerUp()
{

}

Vector2 PowerUp::GetPosition()
{
	return position;
}

float PowerUp::GetRadius()
{
	return radius;
}

Color PowerUp::GetColor()
{
	return color;
}

bool PowerUp::GetActive()
{
	return active;
}

void PowerUp::SetTime(float _time)
{
	time = _time;
}

void PowerUp::SetPosition(Vector2 _position)
{
	position = _position;
}

void PowerUp::SetRadius(float _radius)
{
    windowReSizeHeight = GetScreenHeight() / screenHeight;

	radius = _radius * windowReSizeHeight;
}

void PowerUp::SetActive(bool _active)
{
	active = _active;
}

void PowerUp::SetColor(Color _color)
{
	color = _color;
}

void PowerUp::Draw()
{
	if (active)
		DrawCircleV(position, radius, YELLOW);
	else
		DrawCircleV(position, radius, Fade(LIGHTGRAY, 0.3f));
}

void PowerUp::Update()
{
	time += GetFrameTime();

	if (time >= 20)
	{
		if (!active)
		{
			position = {((float)GetRandomValue(0, GetScreenWidth())),((float)GetRandomValue(0, GetScreenHeight())) };
		}
		active = true;
	}
}

float PowerUp::GetTime()
{
	return time;
}
