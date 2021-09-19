#pragma once
#include "raylib.h"

class PowerUp
{
	private:
		Vector2 position;
		float radius;
		Color color;
		bool active;
	public:
		PowerUp();
		~PowerUp();
		Vector2 GetPosition();
		float GetRadius();
		Color GetColor();
		bool GetActive();

		void SetPosition(Vector2 _position);
		void SetRadius(float _radius);
		void SetActive(bool _active);
		void SetColor(Color _color);
		void Draw();
		void Update();
};

