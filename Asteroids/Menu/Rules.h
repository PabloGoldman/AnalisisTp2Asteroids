#pragma once
#include "Managers/SceneManager.h"
#include "raylib.h"

class Rules
{
private:
	SceneManager* scene;

	const float screenWidth = 800;
	const float screenHeight = 450;

	float windowReSizeWidth = GetScreenWidth() / screenWidth;
	float windowReSizeHeight = GetScreenHeight() / screenHeight;

public:

	void InRules();
	void DrawRules();
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput();
};

