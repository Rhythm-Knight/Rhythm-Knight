#pragma once
#include "SceneManager.h"
#include "AudioManager.h"
#include "TextureManager.h"
#include "Player.h"

class GameManager {
public:
	SceneManager scene;
	AudioManager audio;
	TextureManager textures;
	Player player;

protected:

};