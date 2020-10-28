#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <map>

class TextureManager {
public:
	TextureManager();
	static sf::Texture& GetTexture(std::string const& filename);

protected:
	std::map<std::string, sf::Texture> m_Textures;
	static TextureManager* m_s_Instance;

};
#endif