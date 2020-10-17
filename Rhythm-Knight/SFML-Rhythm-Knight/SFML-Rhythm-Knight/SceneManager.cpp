
#include "SceneManager.h"
#include <iostream>
#include <vector>
#include <math.h>

void SceneManager::dispBattle()
{
	//sf::Vector2f shape1;
	std::vector<sf::Vector2f*> shapes;
	sf::Clock gameclock;
	sf::Time gameTime;
	sf::Time gameTimeDelta;
	float time_remain = 30.0f;
	float gameTimeDelta_secs = 0;
	int cuurent_second = 0, new_second = 0;
	shapes.push_back(new sf::Vector2f);
	while(gameTimeDelta_secs < time_remain)
	{
		gameTimeDelta = gameclock.restart();
		gameTime += gameTimeDelta;
		gameTimeDelta_secs = gameTime.asSeconds();
		new_second = floor(gameTimeDelta_secs);

		if (new_second > cuurent_second)
		{
			cuurent_second = new_second;
			if ((cuurent_second % 5) == 0)
			{
				shapes.push_back(new sf::Vector2f);
			}


			std::vector<sf::Vector2f*>::const_iterator shape_iter;
			std::cout << "Cycling through shapes" << std::endl;
			for (shape_iter = shapes.begin(); shape_iter != shapes.end(); ++shape_iter)
			{
				//(*shape_iter)->Attack();
				std::cout << "shape's Y is: " << (*shape_iter)->y << ", Seconds of game: " << gameTimeDelta_secs << std::endl;
				(*shape_iter)->y += 1;
			}
		}
	}
}