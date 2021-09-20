#pragma once
#include "raylib.h"

class PowerUp
{
	private:
		const float screenWidth = 800;
		const float screenHeight = 450;

		float windowReSizeWidth = GetScreenWidth() / screenWidth;
		float windowReSizeHeight = GetScreenHeight() / screenHeight;

		Vector2 position;
		float radius;
		Color color;
		bool active;
		float time;

	public:
		PowerUp();
		~PowerUp();
		Vector2 GetPosition();
		float GetRadius();
		Color GetColor();
		bool GetActive();

		void SetTime(float _time);
		void SetPosition(Vector2 _position);
		void SetRadius(float _radius);
		void SetActive(bool _active);
		void SetColor(Color _color);
		void Draw();
		void Update();
};

