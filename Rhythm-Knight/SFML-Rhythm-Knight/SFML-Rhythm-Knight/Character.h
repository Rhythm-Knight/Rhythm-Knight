#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Character {
public:
	virtual void spawn(int health, int speed, int x, int y);
	virtual void update(float elapsedTime, sf::Vector2i mousePosition);
	int getHealth();
	sf::Sprite getSprite();
	sf::Vector2i getPosition();

private:
	sf::Sprite m_sprite;
	sf::Texture m_texture;
	sf::Vector2i m_position;

	sf::Vector2f m_screenResolution;

	sf::IntRect m_arena;
	int m_tileSize;

	int m_health;
	int m_speed;
	bool m_isAlive;
};