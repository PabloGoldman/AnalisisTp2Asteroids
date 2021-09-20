#pragma once
#include "raylib.h"
#include "Text.h"
#include <iostream>
class Button
{
private:
	Text* text;

	Color color;
	Rectangle rectangle;
	bool isActive = false;

	const float screenWidth = 800;
	const float screenHeight = 450;

	float windowReSizeWidth = GetScreenWidth() / screenWidth;
	float windowReSizeHeight = GetScreenHeight() / screenHeight;

public:
	Button();
	~Button();

	Rectangle GetRectangle();
	Color GetColor();

	int GetFontSize();

	Font GetFont();

	std::string GetText();

	int GetSpaceBetweenLetters();

	int GetWidth();
	int GetHeight();
	bool GetActive();

	void SetActive(bool _isActive);
	void SetText(std::string txt);
	void SetColor(Color _color);
	void SetWidth(int _width);
	void SetHeight(int _height);
	void SetRectanglePos(int posX, int posY);

	void DrawButton(Rectangle rectangle, const char text[]);

};

