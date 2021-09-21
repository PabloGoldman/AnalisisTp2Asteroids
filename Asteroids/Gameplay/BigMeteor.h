#pragma once
#include "raylib.h"
class BigMeteor
{
	private:
		const float screenWidth = 800;
		const float screenHeight = 450;

		float windowReSizeWidth = GetScreenWidth() / screenWidth;
		float windowReSizeHeight = GetScreenHeight() / screenHeight;

		Vector2 speed;
		Vector2 position;
		float radius;
		Color color;
		bool active;

	public:
		BigMeteor();
		~BigMeteor();

		Vector2 GetSpeed();
		Vector2 GetPosition();
		float GetRadius();
		Color GetColor();
		bool GetActive();

		void SetSpeed(Vector2 _speed);
		void SetPosition(Vector2 _position);
		void SetRadius(float _radius);
		void SetActive(bool _active);
		void SetColor(Color _color);
		void Draw();
		void Update();
};

