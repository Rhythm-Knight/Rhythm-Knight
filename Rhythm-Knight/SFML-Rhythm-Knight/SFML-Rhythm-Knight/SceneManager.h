#pragma once
#include <SFML/Graphics.hpp>

class SceneManager {
public:
	void dispMainMenu();
	void dispDungeon();
	void dispPreBattle();
	void dispBattle();
	void dispShop();
private:
	sf::Sprite* createspritesarray(std::vector<sf::Sprite*> &input_vec);

};