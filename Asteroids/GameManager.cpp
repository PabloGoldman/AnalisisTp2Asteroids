#include "GameManager.h"
#include "raylib.h"

GameManager::GameManager()
{
	_audioManager = new AudioManager();
	_endGameScreen = new EndGameScreen();
	_sceneManager = new SceneManager();
	_menu = new Menu();
	_gameplay = new Gameplay();
	_credits = new Credits();
	_rules = new Rules();

	screenWidth = 800;
	screenHeight = 450;
	fontSize = 40;
	isPlaying = true;
	gameplayInited = false;
	menuInited = false;
	creditsInited = false;
	rulesInited = false;
	modeScreenInited = false;
	endGameScreenInited = false;
}

GameManager::~GameManager()
{
	delete _audioManager;
	delete _sceneManager;
	delete _menu;
	delete _gameplay;
	delete _credits;
	delete _rules;
	delete _endGameScreen;
}

void GameManager::RunGame()
{
	InitWindow(screenWidth, screenHeight, "Pong");

	while (!WindowShouldClose() && isPlaying)    // Detect window close button or ESC key
	{
		BeginDrawing();
		ClearBackground(BLUE);

		PlayMusicInMenu();

		switch (_sceneManager->GetScene())
		{
		case Scene::MENU:
			if (!menuInited) //Para que no se inicialicen las variables repetidamente
			{
				InitAllMenuData();
				menuInited = true;
			}
			_menu->InMenu();
			break;
		case Scene::GAME:
			if (!gameplayInited)
			{
				InitAllGameData();
				gameplayInited = true;
			}
			_gameplay->InGame();
			break;
		case Scene::ENDGAME:
			if (!endGameScreenInited)
			{
				InitAllEndGameScreenData();
				endGameScreenInited = true;
			}
			_endGameScreen->InEndGameScreen();
			break;
		case Scene::RULES:
			if (!rulesInited)
			{
				InitAllRulesData();
				rulesInited = true;
			}
			_rules->InRules();
			break;
		case Scene::CREDITS:
			if (!creditsInited)
			{
				InitAllCreditsData();
				creditsInited = true;
			}
			_credits->InCredits();
			break;
		case Scene::EXIT:
			isPlaying = false;
			break;
		default:
			break;
		}
		EndDrawing();
	}
	CloseWindow();        // Close window and OpenGL context
}


void GameManager::InitAllGameData()
{
	_gameplay->SetEndGameScreen(_endGameScreen);
	_gameplay->SetAudioManager(_audioManager);
	_gameplay->SetSceneManager(_sceneManager);
	_gameplay->InitGameplay();
}

void GameManager::InitAllMenuData()
{
	_menu->InitMenuData();
	_menu->SetAudioManager(_audioManager);
	_menu->SetSceneManager(_sceneManager);
}

void GameManager::InitAllCreditsData()
{
	_credits->SetSceneManager(_sceneManager);
}

void GameManager::InitAllEndGameScreenData()
{
	_endGameScreen->SetSceneManager(_sceneManager);
	_endGameScreen->InitEndGameScreenData();
}

void GameManager::PlayMusicInMenu()
{
	if (_sceneManager->GetScene() != Scene::GAME)
		_audioManager->PlayMenuMusic();
}

void GameManager::InitAllRulesData()
{
	_rules->SetSceneManager(_sceneManager);
}


