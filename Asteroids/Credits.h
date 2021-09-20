#pragma once
#include "SceneManager.h"
#include "raylib.h"

class Credits
{
private:
	SceneManager* scene;

	const float screenWidth = 800;
	const float screenHeight = 450;

	float windowReSizeWidth = GetScreenWidth() / screenWidth;
	float windowReSizeHeight = GetScreenHeight() / screenHeight;

public:

	void InCredits();
	void DrawCredits();
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput();
};

