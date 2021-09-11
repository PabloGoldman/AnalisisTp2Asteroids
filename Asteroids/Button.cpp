#include "Button.h"

static int correctionX = 40;
static int correctionY = 16;
static int optionButtonHeight = 15;
static int optionButtonWidth = 15;

Button::Button()
{
	text = new Text();

	rectangle.height = 200;
	rectangle.width = 200;
	color = BLACK;
}

Button::~Button()
{
	delete text;
}

//-------------------------------------------GETTERS------------------------------

Rectangle Button::GetRectangle()
{
	return rectangle;
}

Color Button::GetColor()
{
	return color;
}

int Button::GetWidth()
{
	return rectangle.width;
}

int Button::GetHeight()
{
	return rectangle.height;
}

bool Button::GetActive()
{
	return isActive;
}

std::string Button::GetText()
{
	return text->GetText();
}

Font Button::GetFont()
{
	return text->GetTextFont();
}

int Button::GetFontSize()
{
	return text->GetSize();
}

int Button::GetSpaceBetweenLetters()
{
	return text->GetSpaceBetweenLetters();
}

//--------------------------------------------SETTERS---------------------------------

void Button::SetText(std::string txt)
{
	text->SetText(txt);
}

void Button::SetActive(bool _isActive)
{
	isActive = _isActive;
}

void Button::SetWidth(int _width)
{
	rectangle.width = _width;
}

void Button::SetHeight(int _height)
{
	rectangle.height = _height;
}

void Button::SetRectanglePos(int posX, int posY)
{
	rectangle.x = posX;
	rectangle.y = posY;
}

void Button::SetColor(Color _color)
{
	color = _color;
}

//-------------------------------------------FUNCIONES---------------------------------

void Button::DrawButton(Rectangle rectangle, const char text[])
{
	Font font = GetFontDefault();

	DrawTextRec(font, text, GetRectangle(), GetFontSize(), GetSpaceBetweenLetters(), false, GetColor());

	if (isActive) //Dibuja el boton de la izquierda, el que muestra la seleccion
	{
		DrawRectangle(GetRectangle().x - correctionX, GetRectangle().y + correctionY, optionButtonHeight, optionButtonWidth, GetColor());
	}
}
