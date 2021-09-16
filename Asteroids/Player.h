#pragma once
#include "raylib.h"

class Player
{
private:

	Vector2 position;
	Vector2 speed;
	float acceleration;
	float rotation;
	Vector3 collider;

	float height;

	Color color;
	int points;

public:
	Player();
	~Player();

	Color GetColor();

	Vector2 GetSpeed();
	Vector2 GetPos();
	int GetPoints();
	float GetAcceleration();
	float GetRotation();
	float GetHeight();

	//void SetWidth(int _width);
	void AddPosition(Vector2 _pos);
	void AddRotation(float _rotation);
	void AddAcceleration(float _acceleration);
	void SetAcceleration(float _acceleration);
	void SetRotation(float _rotation);
	void SetSpeed(Vector2 _speed);
	void SetColor(Color _color);
	void SetHeight(int _height);
	void SetPoints(int _points);
	void SetPlayerPos(Vector2 _position);
	void AddPoints(int _points);
	void DrawPlayer();
	void WallCollision();
};


