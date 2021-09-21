#include "Managers/GameManager.h"

void main()
{
	GameManager* gameManager = new GameManager();

	gameManager->RunGame();

	delete gameManager;
}