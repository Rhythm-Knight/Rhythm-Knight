#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Character {
public:

protected:

private:
	sf::Sprite m_Sprite;
	sf::Texture m_Texture;

	sf::Vector2f m_Position;
	sf::Vector2f m_Resolution;

	sf::IntRect m_Arena;

	int m_TileSize;
};