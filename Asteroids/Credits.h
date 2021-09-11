#pragma once
#include "SceneManager.h"
class Credits
{
private:
	SceneManager* scene;
public:

	void InCredits();
	void DrawCredits();
	void SetSceneManager(SceneManager* sm);
	void ReturnToMenu();
	void CheckInput();
};

