#include "AudioManager.h"

const float standardVolume = 0.3f;

AudioManager::AudioManager()
{
	InitAudioDevice();

	menuMusic = LoadMusicStream("res/assets/Music/MenuMusic.mp3");
	gameMusic = LoadMusicStream("res/assets/Music/GameMusic.mp3");
	optionSound = LoadSound("res/assets/Music/OptionSound.mp3");

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
	StopMusicStream(menuMusic);
	StopMusicStream(gameMusic);
}

void AudioManager::PlayMenuMusic()
{
	StopMusicStream(gameMusic);
	PlayMusicStream(menuMusic);
	SetMusicVolume(menuMusic, standardVolume);
	UpdateMusicStream(menuMusic);
}

void AudioManager::PlayGameMusic()
{
	PlayMusicStream(gameMusic);
	StopMusicStream(menuMusic);
	SetMusicVolume(gameMusic, standardVolume);
	UpdateMusicStream(gameMusic);
}

void AudioManager::PlayOptionSound()
{
	SetSoundVolume(optionSound, standardVolume);
	PlaySound(optionSound);
}

