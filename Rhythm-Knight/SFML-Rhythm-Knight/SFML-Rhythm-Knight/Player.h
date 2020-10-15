#pragma once
#include "Character.h"
#include "Inventory.h"

class Player : Character {
public:
	Inventory inventory;
	int currency;

	Player();

	void spawn(sf::IntRect arena, sf::Vector2f resolution, int tileSize);

	// Where is the player
	sf::FloatRect getPosition();
	sf::Vector2f getCenter();
	int getRotation();

	sf::Sprite getSprite();

	int getHealth();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

	void update(float elapsedTime, sf::Vector2i mousePosition);

protected:

private:
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	int m_Health;
	int m_Speed;
};

