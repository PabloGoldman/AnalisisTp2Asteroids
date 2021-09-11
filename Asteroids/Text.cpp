#include "Text.h"

Text::Text()
{
	size = 50;
	color = BLACK;
	font = GetFontDefault();
	spaceBetweenLetters = 5;
}

Text::~Text()
{

}

//---------------------------------------------------GETTERS--------------------

int Text::GetSize()
{
	return size;
}

std::string Text::GetText()
{
	return tx;
}

Color Text::GetColor()
{
	return color;
}

Font Text::GetTextFont()
{
	return font;
}

int Text::GetSpaceBetweenLetters()
{
	return spaceBetweenLetters;
}

//---------------------------------------------------SETTERS------------------

void Text::SetSize(int _size)
{
	size = _size;
}

void Text::SetColor(Color _color)
{
	color = _color;
}

void Text::SetFont(Font _font)
{
	font = _font;
}

void Text::SetText(std::string txt)
{
	tx = txt;
}

void Text::SetSpaceBetweenLetters(int _space)
{
	spaceBetweenLetters = _space;
}


