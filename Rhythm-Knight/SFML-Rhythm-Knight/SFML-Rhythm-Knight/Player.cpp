#include "Player.h"
#include "TextureManager.h"

Player::Player()
{
	m_sprite.setTexture(TextureManager::GetTexture("Assets/player.png"));
}

void Player::spawn(sf::Vector2f position) {
	m_position.x = position.x;
	m_position.y = position.y;
}

sf::Sprite Player::getSprite() {
	return m_sprite;
}

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
	m_sprite.setScale(-1.0f, 1.0f);
}

void Player::moveRight() {
	m_position.x += 1;
	m_sprite.setScale(1.0f, 1.0f);
}

void Player::moveUp() {
	m_position.y -= 1;
}

void Player::moveDown() {
	m_position.y += 1;
}