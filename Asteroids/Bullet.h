#pragma once
#include "raylib.h"
class Bullet
{
	private:
        Vector2 position;
        Vector2 speed;
        float radius;
        float rotation;
        int lifeSpawn;
        bool active;
        Color color;

	public:
        Vector2 GetPosition();
        Vector2 GetSpeed();
        float GetRadius();
        float GetRotation();
        int GetLifeSpawn();
        bool GetIsActive();
        Color GetColor();

        void SetPosition(Vector2 pos);
        void SetSpeed(Vector2 _speed);
        void SetRadius(float _radius);
        void SetLifeSpawn(int _lifeSpawn);
        void SetIsActive(bool _active);
        void SetColor(Color _color);
        void SetRotation(float _rotation);
        
        void Update();
        void Movement();
        void LifeTime();
        void WallCollision();
        void ResetData();
        void Draw();

};

