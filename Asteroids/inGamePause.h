#pragma once
#include "SceneManager.h"
#include "Button.h"	


enum class OPTION { RESUME, QUIT };

class InGamePause
{
private:
	OPTION option;

	SceneManager* sceneManager;
	Button* resume;
	Button* quit;

	bool inPause;

	void CheckInput();
	void DrawPauseMenu();
	void Update();

public:
	InGamePause();
	~InGamePause();

	OPTION GetMenuOption();

	bool GetInPause();

	void SetInPause(bool _inPause);
	void SetSceneManager(SceneManager* sc);
	void InPause();
	void SetMenuOption(OPTION _option);
	void SetButtonsData();
	void InitInPauseData();
};

