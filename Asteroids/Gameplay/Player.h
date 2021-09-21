#pragma once
#include "raylib.h"
#include "Bullet.h"

class Player
{
private:
	const float screenWidth = 800;
	const float screenHeight = 450;

	float windowReSizeWidth = GetScreenWidth() / screenWidth;
	float windowReSizeHeight = GetScreenHeight() / screenHeight;

	Bullet* bullet[3];
	Vector2 position;
	Vector2 speed;
	Vector2 acceleration;
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
	Vector2 GetAcceleration();
	float GetRotation();
	float GetHeight();

	void SetBullets(Bullet* _bullet);
	void AddPosition(Vector2 _pos);
	void AddRotation(float _rotation);
	void AddAcceleration(float _accelerationX, float _accelerationY);
	void SetAcceleration(Vector2 _acceleration);
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


