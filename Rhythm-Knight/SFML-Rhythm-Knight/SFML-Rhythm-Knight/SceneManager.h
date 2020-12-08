#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class SceneManager {
public:
	void dispMainMenu();
	void dispDungeon();
	void dispPreBattle();
	void dispBattle();
	void dispShop();

	const int TILE_SIZE = 50;
	const int VERTS_IN_QUAD = 4;
	int** nextLevel(VertexArray& rVaLevel);
	Vector2i getMainAreaSize();

private:
	Vector2i m_mainAreaSize;
	sf::Sprite* createspritesarray(std::vector<sf::Sprite*>& input_vec);
};
#endif