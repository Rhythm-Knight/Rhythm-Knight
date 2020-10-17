#pragma once
#include "Character.h"
#include "Inventory.h"

class Player : public Character{
public:
	Inventory m_inventory;
	int m_currency;

	// Where is the player
	sf::Vector2i getPosition();
	bool getRotation();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

private:
	sf::Sprite m_sprite;
	sf::Vector2i m_position;
	bool m_rotation;
};