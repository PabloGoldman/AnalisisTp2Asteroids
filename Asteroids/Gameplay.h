#pragma once
#include "SceneManager.h"
#include "HUD.h"
#include "AudioManager.h"
#include "EndGameScreen.h"
#include "InGamePause.h"

class Gameplay
{
	private:
		SceneManager* scene;
		EndGameScreen* endGameScreen;
		AudioManager* audioManager;
		InGamePause* pause;
		HUD* hud;

		bool inPause;

		void Input();
		void Update();
		void Draw();

	public:
		Gameplay();
		~Gameplay();

		bool GetInPause();

		void SetInPause(bool pause);

		void SetSceneManager(SceneManager* sc);
		void SetEndGameScreen(EndGameScreen* eg);
		void SetInGamePauseData();
		void SetAudioManager(AudioManager* am);

		void InGame();
		void InitGameplay();
};
