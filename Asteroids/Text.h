#pragma once
#include "raylib.h"	
#include <iostream>

class Text
{
private:

	std::string tx = "";
	Vector2 pos = { 0,0 };
	int size;
	Color color;
	Font font = GetFontDefault();
	int spaceBetweenLetters;
public:
	Text();
	~Text();

	int GetSize();
	Color GetColor();
	Font GetTextFont();
	int GetSpaceBetweenLetters();
	std::string GetText();


	void SetText(std::string txt);
	void SetSize(int _size);
	void SetColor(Color _color);
	void SetFont(Font _font);
	void SetSpaceBetweenLetters(int _space);
};

