#pragma once
#include "Button.h"
#include "SceneManager.h"

enum class ENDGAMEOPTION { PLAY, QUIT };

class EndGameScreen
{
private:
	ENDGAMEOPTION option;

	SceneManager* sceneManager;

	Button* gameFinished;
	Button* replay;
	Button* quit;


	void CheckInput();
	void DrawEndGameScreen();
	void Update();

public:
	EndGameScreen();
	~EndGameScreen();

	ENDGAMEOPTION GetOption();

	bool player1Win;

	void SetWinPlayer(bool player1);
	void SetOption(ENDGAMEOPTION _option);
	void SetSceneManager(SceneManager* sc);
	void SetButtonsData();
	void InitEndGameScreenData();
	void InEndGameScreen();
};
