#include "Gameplay.h"

const int screenWidth = 800;
const int screenHeight = 450;
const int fontSize = 40;

Gameplay::Gameplay()
{
	hud = new HUD();
	pause = new InGamePause();

	inPause = false;
}

Gameplay::~Gameplay()
{

}

bool Gameplay::GetInPause()
{
	return inPause;
}

void Gameplay::SetSceneManager(SceneManager* sc)
{
	scene = sc;
}

void Gameplay::SetEndGameScreen(EndGameScreen* eg)
{
	endGameScreen = eg;
}

void Gameplay::SetInGamePauseData()
{
	pause->InitInPauseData();
	pause->SetSceneManager(scene);
}

void Gameplay::SetAudioManager(AudioManager* am)
{
	audioManager = am;
}

void Gameplay::InitGameplay()
{
	pause->SetSceneManager(scene);
}



