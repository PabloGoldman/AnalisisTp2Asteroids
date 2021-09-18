#pragma once
#include "raylib.h"
class SmallMeteor
{
private:
	Vector2 speed;
	Vector2 position;
	float radius;
	Color color;
	bool active;

public:
	SmallMeteor();
	~SmallMeteor();

	Vector2 GetSpeed();
	Vector2 GetPosition();
	float GetRadius();
	Color GetColor();
	bool GetActive();

	void SetColor(Color _color);
	void SetSpeed(Vector2 _speed);
	void SetPosition(Vector2 _position);
	void SetRadius(float _radius);
	void SetActive(bool _active);
	void Draw();
	void Update();
};

