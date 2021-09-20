#pragma once
#include "raylib.h"
class Bullet
{
	private:
        const float screenWidth = 800;
        const float screenHeight = 450;

        float windowReSizeWidth = GetScreenWidth() / screenWidth;
        float windowReSizeHeight = GetScreenHeight() / screenHeight;

        Vector2 position;
        Vector2 speed;
        float radius;
        float rotation;
        float lifeSpawn;
        float lifeTime;
        bool active;
        Color color;

	public:
        Bullet();
        ~Bullet();

        Vector2 GetPosition();
        Vector2 GetSpeed();
        float GetRadius();
        float GetRotation();
        float GetLifeSpawn();
        bool GetIsActive();
        Color GetColor();

        void SetPosition(Vector2 pos);
        void SetSpeed(Vector2 _speed);
        void SetRadius(float _radius);
        void SetLifeSpawn(float _lifeSpawn);
        void SetIsActive(bool _active);
        void SetColor(Color _color);
        void SetRotation(float _rotation);
        void SetLifeTime(float _lifetime);
        
        void Update();
        //void Movement();
        void LifeTime();
        void WallCollision();
        void ResetData();
        void Draw();
        void AddPosition(Vector2 pos);
};

