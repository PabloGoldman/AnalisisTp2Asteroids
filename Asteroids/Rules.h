#pragma once
#include "SceneManager.h"
class Rules
{
private:
	SceneManager* scene;
public:

	void InRules();
	void DrawRules();
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput();
};

