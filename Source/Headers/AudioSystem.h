#pragma once
#include "stdafx.h"
#include "GameEventMediator.h"
class AudioSystem
{
private:
	sf::Music music;
	sf::Music level1Music;
	sf::Music level2Music;
	sf::Music level3Music;
	sf::Sound jumpSound;
	sf::Sound buttonSound;
	sf::Sound coinSound;
	sf::SoundBuffer jumpSoundBuffer;
	sf::SoundBuffer buttonSoundBuffer;
	sf::SoundBuffer coinSoundBuffer;

	GameEventMediator* eventMediator;
public:
	AudioSystem();
	void playMusic();
	void stopMusic();
	void playLevel1Music();
	void stopLevel1Music();
	void playLevel2Music();
	void stopLevel2Music();
	void playLevel3Music();
	void stopLevel3Music();
	void playJumpSound();
	void stopJumpSound();
	void playbuttonSound();
	void stopButtonSound();
	void playCoinSound();
	void stopCoinSound();

	void stopAllMusic();

	void setEventMediator(GameEventMediator* eventMediator);
};

