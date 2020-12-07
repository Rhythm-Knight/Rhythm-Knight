#include "WrapperShape.h"
#include "TextureManager.h"

WrapperShape::WrapperShape(std::string texture, sf::Vector2f position) 
{
	spawn(texture, position);
}

void WrapperShape::spawn(std::string texture, sf::Vector2f position) 
{
	m_sprite.setTexture(TextureManager::GetTexture(texture));
	m_position = position;
	m_sprite.setPosition(m_position.x, m_position.y);
}

sf::Vector2f WrapperShape::getPosition() 
{
	m_position = m_sprite.getPosition();
	return m_position;
}

sf::Sprite WrapperShape::getSprite()
{
	return m_sprite;
}

void WrapperShape::setPosition(sf::Vector2f position) 
{
	m_position = position;
	m_sprite.setPosition(m_position.x, m_position.y);
}

void WrapperShape::killShape()
{
	isAlive = false;
}

bool WrapperShape::checkAlive()
{
	return isAlive;
}
