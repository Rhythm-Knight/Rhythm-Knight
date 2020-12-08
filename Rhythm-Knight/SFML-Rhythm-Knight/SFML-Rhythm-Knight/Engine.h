#pragma once
#include <SFML/Graphics.hpp>
#include "TextureManager.h"
#include "Player.h"
#include "Enemy.h"
#include "SceneManager.h"

using namespace sf;

class Engine
{
private:
	// The texture holder
	TextureManager th;

	//Player and Enemy
	Player m_Player;
	//Enemy m_Enemy;

	// A class to manage all the levels
	SceneManager m_LM;

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;

	// The force pushing the characters down
	const int GRAVITY = 300;

	// A regular RenderWindow
	RenderWindow m_Window;

	// The main Views
	View m_MainView;

	// Three views for the background
	View m_BGMainView;

	// Declare a sprite and a Texture for the background
	Sprite m_BackgroundSprite;
	Texture m_BackgroundTexture;

	// Is the game currently playing?
	bool m_Playing = false;

	// Is character 1 or 2 the current focus?
	bool m_Character1 = true;


	// The vertex array for the level design
	VertexArray m_VALevel;

	// The 2d array with the map for the level
	// A pointer to a pointer
	int** m_ArrayLevel = NULL;

	// Texture for the background and the level tiles
	Texture m_TextureTiles;
	
	// Private functions for internal use only
	void input();
	void update();
	void draw();
	void loadMap();

public:
	
	// The Engine constructor
	Engine();

	// Run will call all the private functions
	void run();

};
