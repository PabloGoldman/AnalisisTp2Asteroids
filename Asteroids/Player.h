#pragma once
#include "raylib.h"
#include "Bullet.h"

class Player
{
private:

	Bullet* bullet[10];
	Vector2 position;
	Vector2 speed;
	float acceleration;
	float rotation;
	Vector3 collider;

	float height;

	Color color;
	int points;

	int bulletTaken = 0;

public:
	Player();
	~Player();

	Color GetColor();

	Vector2 GetSpeed();
	Vector2 GetPos();
	Vector3 GetCollider();
	int GetPoints();
	float GetAcceleration();
	float GetRotation();
	float GetHeight();

	void SetBullets(Bullet* _bullet);
	void AddPosition(Vector2 _pos);
	void AddRotation(float _rotation);
	void AddAcceleration(float _acceleration);
	void SetAcceleration(float _acceleration);
	void SetRotation(float _rotation);
	void SetSpeed(Vector2 _speed);
	void SetColor(Color _color);
	void SetHeight(int _height);
	void SetPoints(int _points);
	void SetCollider(Vector3 _collider);
	void SetPlayerPos(Vector2 _position);
	void AddPoints(int _points);
	void Draw();
	void WallCollision();
	void Shoot();
	void Update();
};


