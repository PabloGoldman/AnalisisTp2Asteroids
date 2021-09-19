#include "PowerUp.h"

PowerUp::PowerUp()
{
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

void PowerUp::SetPosition(Vector2 _position)
{
	position = _position;
}

void PowerUp::SetRadius(float _radius)
{
	radius = _radius;
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
