
#include "SceneManager.h"
#include "TextureManager.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace sf;

void SceneManager::dispBattle()
{
	//sf::Vector2f shape1;
	//std::vector<sf::Vector2f*> shapes;
	sf::Clock gameclock;
	sf::Time gameTime;
	sf::Time gameTimeDelta;

	float time_remain = 30.0f;
	float gameTimeDelta_secs = 0;
	float shapespeed = 0.05f;
	int current_second = 0, new_second = 0;

	/*###########################--draw shapes--###########################*/

	TextureManager holder;
	Sprite* spritesarray = NULL;
	std::vector<sf::Sprite*> sprite_vec;
	std::vector<sf::Sprite> sprite_vec_temp;
	std::vector<sf::Sprite*>::const_iterator sprite_iter;
	std::vector<int> slider_vec_position;
	std::vector<int>::const_iterator slider_vec_position_iter;
	int counter_addshape = 0, counter_deadshape = 0;
	sf::Vector2f spriteposition;
	// Get the screen resolution and create an SFML window
	sf::Vector2f resolution;
	resolution.x = sf::VideoMode::getDesktopMode().width;
	resolution.y = sf::VideoMode::getDesktopMode().height;

	sf::RenderWindow window(sf::VideoMode(resolution.x, resolution.y),
		"Rythm Game", sf::Style::Fullscreen);

	//window.setMouseCursorVisible(true);

	sf::View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	// The boundaries of the arena
	sf::IntRect arena;

	sf::VertexArray background;

	sf::Sprite gamebackground, tempsprite;
	sf::Texture Backgroundtexture = TextureManager::GetTexture("Assets/temp.png");//1280x1024
	gamebackground.setTexture(Backgroundtexture);
	gamebackground.setPosition(0, 0);


	Texture slidertexture = TextureManager::GetTexture("Assets/slider.png");//100x100
	Texture tracktexture = TextureManager::GetTexture("Assets/slidertrack.png");//20x500
	Texture endpointtexture = TextureManager::GetTexture("Assets/endpoint.png");//100x100

	sprite_vec.push_back(new Sprite());//first 4 is slider tracks
	sprite_vec.push_back(new Sprite());
	sprite_vec.push_back(new Sprite());
	sprite_vec.push_back(new Sprite());
	sprite_vec.push_back(new Sprite());//second 4 is endpoints
	sprite_vec.push_back(new Sprite());
	sprite_vec.push_back(new Sprite());
	sprite_vec.push_back(new Sprite());

	sf::Vector2f slidertrack_start_coordinates, slider_start_coordinates, endpoint_start_coordinates;
	slidertrack_start_coordinates.x = 140;
	slidertrack_start_coordinates.y = 150;
	endpoint_start_coordinates.x = 100;
	endpoint_start_coordinates.y = 600;
	slider_start_coordinates.x = 100;
	slider_start_coordinates.y = 100;
	for (sprite_iter = sprite_vec.begin(); sprite_iter != sprite_vec.end(); ++sprite_iter)
	{
		if (counter_addshape < 4)//assign texture and position slider track
		{
			(*sprite_iter)->setTexture(tracktexture);
			(*sprite_iter)->setPosition(slidertrack_start_coordinates.x 
				+ (200 * (counter_addshape %4)), slidertrack_start_coordinates.y);
		}
		else//assign texture and position slider endpoint
		{
			(*sprite_iter)->setTexture(endpointtexture);
			(*sprite_iter)->setPosition(endpoint_start_coordinates.x 
				+ (200 * (counter_addshape % 4)), endpoint_start_coordinates.y);
		}
		counter_addshape++;
	}
	//shapes.push_back(new sf::Vector2f);
	sprite_vec.push_back(new Sprite());
	sprite_vec.back()->setTexture(slidertexture);
	sprite_vec.back()->setPosition(slider_start_coordinates.x, slider_start_coordinates.y);
	counter_addshape = 1;


	while (window.isOpen())
	{
		while (gameTimeDelta_secs < time_remain)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameTimeDelta_secs == time_remain;
				window.close();
			}
			gameTimeDelta = gameclock.restart();
			gameTime += gameTimeDelta;
			gameTimeDelta_secs = gameTime.asSeconds();
			new_second = floor(gameTimeDelta_secs);

			if (new_second > current_second)
			{
				current_second = new_second;
				if ((current_second % 2) == 0)
				{
					sprite_vec.push_back(new Sprite());
					sprite_vec.back()->setTexture(slidertexture);
					sprite_vec.back()->setPosition(slider_start_coordinates.x
						+ (200 * (counter_addshape % 4)), slider_start_coordinates.y);
					counter_addshape++;
					if (counter_addshape == 4)
					{
						counter_addshape = 0;
					}
				}

				//Display Background
				int BattleBackground(VertexArray & rVA, IntRect arena);
				//Player* p1 = new Player(); (Character) 
				//p1->controls();
				//Enemy e1 = new Enemy(); (Character) 
				//Display stats Player and Enemy
				//Display sprites Preferably Player(s) on left and Enemy(s) on right side of screen
				//Display (score) Gold and multiplier
				//Display the rhythmn keys to be entered (arrows)

			}

			counter_deadshape = 0;
			for (sprite_iter = (sprite_vec.begin() + 8); sprite_iter != sprite_vec.end(); ++sprite_iter)
			{
				spriteposition = (*sprite_iter)->getPosition();
				(*sprite_iter)->setPosition(spriteposition.x, (spriteposition.y + shapespeed));
				if (spriteposition.y >= 605)
				{
					slider_vec_position.push_back(counter_deadshape);
				}
				counter_deadshape++;
			}//slider_vec_position
			//dead sliders
			for (slider_vec_position_iter = slider_vec_position.begin();
				slider_vec_position_iter != slider_vec_position.end(); ++slider_vec_position_iter)
			{
				sprite_vec.erase(sprite_vec.begin() + 8 + (*slider_vec_position_iter));
			}//slider_vec_position
			slider_vec_position.clear();

			window.clear();

			window.setView(mainView);

			window.draw(gamebackground);
			//spritesarray = createspritesarray(sprite_vec);
			spritesarray = new Sprite[sprite_vec.size()];
			std::cout << "Sprite vector size: " << sprite_vec.size() << std::endl;
			for (int i = 0; i < sprite_vec.size(); i++)
			{
				spritesarray[i].setPosition(sprite_vec.at(i)->getPosition());
				if (i < 4)
				{
					spritesarray[i].setTexture(tracktexture);;
				}
				else if (i < 8)
				{
					spritesarray[i].setTexture(endpointtexture);
				}
				else
				{
					spritesarray[i].setTexture(slidertexture);
				}
			}
			for (int i = 0; i < sprite_vec.size(); ++i)
			{
				
				window.draw(spritesarray[i]);


				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{
					window.close();
				}
			}

			window.display();

		}//time loop end

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		window.clear();

		window.setView(mainView);

		window.draw(gamebackground);
	}//new loop stuff end

	//sprite locations manually---################################################################

	//slider1.setTexture(slidertexture);//increase x by 200
	//slider1.setPosition(100, 100);
	//slider2.setTexture(slidertexture);
	//slider2.setPosition(300, 100);
	//slider3.setTexture(slidertexture);
	//slider3.setPosition(500, 100);
	//slider4.setTexture(slidertexture);
	//slider4.setPosition(700, 100);

	//track1.setTexture(tracktexture);//increase x by 200
	//track1.setPosition(140, 150);
	//track2.setTexture(tracktexture);
	//track2.setPosition(340, 150);
	//track3.setTexture(tracktexture);
	//track3.setPosition(540, 150);
	//track4.setTexture(tracktexture);
	//track4.setPosition(740, 150);

	//endpoint1.setTexture(endpointtexture);//increase x by 200
	//endpoint1.setPosition(100, 600);
	//endpoint2.setTexture(endpointtexture);
	//endpoint2.setPosition(300, 600);
	//endpoint3.setTexture(endpointtexture);
	//endpoint3.setPosition(500, 600);
	//endpoint4.setTexture(endpointtexture);
	//endpoint4.setPosition(700, 600);

}//method end