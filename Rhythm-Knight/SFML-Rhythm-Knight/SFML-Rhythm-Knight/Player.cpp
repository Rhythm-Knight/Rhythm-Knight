#include "Player.h"

sf::Vector2i Player::getPosition() {
	return m_position;
}

bool Player::getRotation() {
	//true = right 
	//false = left
	return m_rotation;
}

void Player::moveLeft() {
	m_position.x -= 1;
	m_rotation = false;
}

void Player::moveRight() {
	m_position.x += 1;
	m_rotation = true;
}

void Player::moveUp() {
	m_position.y -= 1;
}

void Player::moveDown() {
	m_position.y += 1;
}