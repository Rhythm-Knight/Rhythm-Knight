#include "Character.h"

void Character::spawn(int health, int speed, int x, int y) {
	m_health = health;
	m_speed = speed;
	m_position.x = x;
	m_position.y = y;
}

void Character::update(float elapsedTime, sf::Vector2i mousePosition) {

}

sf::Vector2i Character::getPosition() {
	return m_position;
}

sf::Sprite Character::getSprite() {
	return m_sprite;
}

int Character::getHealth() {
	return m_health;
}