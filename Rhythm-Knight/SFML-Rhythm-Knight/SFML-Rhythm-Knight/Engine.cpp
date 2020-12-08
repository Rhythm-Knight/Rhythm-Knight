#include "stdafx.h"
#include "Engine.h"


Engine::Engine()
{
	// Get the screen resolution and create an SFML window and View
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	m_Window.create(VideoMode(resolution.x, resolution.y),
		"Rhythm Knights",
		Style::Fullscreen);

	// Initialize the full screen view
	m_MainView.setSize(resolution);

	// Two lines below used to create zoomed our screenshots for the book
	//m_BGMainView.zoom(2.5);
	m_MainView.zoom(2.5);
	Player m_player;
	//m_player.setPosition(300,800);


	m_BackgroundTexture = TextureManager::GetTexture(
		"graphics/background.png");

	// Associate the sprite with the texture
	m_BackgroundSprite.setTexture(m_BackgroundTexture);

	// Load the texture for the background vertex array
	m_TextureTiles = TextureManager::GetTexture(
		"graphics/tiles_sheet.png");


}



void Engine::run()
{

	while (m_Window.isOpen())
	{
		input();
		update();
		draw();
	}
}