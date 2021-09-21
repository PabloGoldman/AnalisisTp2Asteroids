#include "SceneManager.h"

SceneManager::SceneManager()
{
	scene = Scene::MENU;
}

SceneManager::~SceneManager()
{

}

Scene SceneManager::GetScene()
{
	return scene;
}

void SceneManager::SetSceneManager(Scene _scene)
{
	scene = _scene;
}
