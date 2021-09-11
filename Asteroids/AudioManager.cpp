#include "AudioManager.h"

const float standardVolume = 0.3f;

AudioManager::AudioManager()
{
	InitAudioDevice();

	musicInited = false;
}

AudioManager::~AudioManager()
{

}

void AudioManager::InitMusic(Music music)
{

}

Music AudioManager::GetMenuMusic()
{
	return menuMusic;
}

void AudioManager::StopAllMusics()
{

}

void AudioManager::PlayMenuMusic()
{
	
}

void AudioManager::PlayGameMusic()
{
	/*PlayMusicStream(gameMusic);
	StopMusicStream(menuMusic);
	SetMusicVolume(gameMusic, standardVolume);
	UpdateMusicStream(gameMusic);*/
}

void AudioManager::PlayOptionSound()
{

}

