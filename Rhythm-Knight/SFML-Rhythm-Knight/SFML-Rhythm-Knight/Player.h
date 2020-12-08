#pragma once
#include "Character.h"

class Player : public Character {
public:
	int m_currency;
	Player();
	void spawn(sf::Vector2f position);
	// Where is the player
	sf::Vector2i getPosition();
	sf::Sprite getSprite();
	bool getRotation();

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

private:
	sf::Sprite m_sprite;
	sf::Vector2i m_position;
	bool m_rotation;
	int Inventory[3] = { 0, 0, 0 };
};