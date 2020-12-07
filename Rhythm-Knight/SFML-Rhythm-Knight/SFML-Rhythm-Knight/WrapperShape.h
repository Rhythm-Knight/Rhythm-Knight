#pragma once
#ifndef WRAPPERSHAPE_H
#define WRAPPERSHAPE_H

#include <SFML\Graphics.hpp>

class WrapperShape {
public:
		WrapperShape(std::string texture, sf::Vector2f position);
	sf::Vector2f getPosition();
	sf::Sprite getSprite();
	void setPosition(sf::Vector2f position);
	void killShape();
	bool checkAlive();
private:
	void spawn(std::string texture, sf::Vector2f position);
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
	bool isAlive = true;
};
#endif // !WRAPPERSHAPE_H
