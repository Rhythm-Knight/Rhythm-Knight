
#include "SceneManager.h"
#include "TextureManager.h"
#include "WrapperShape.h"
#include "ScoreManager.h"
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
	ScoreManager score_manager;

	float time_remain = 30.0f;
	float gameTimeDelta_secs = 0;
	float shapespeed = 0.5f;
	int current_second = 0, new_second = 0;

	/*###########################--draw shapes--###########################*/

	/*###########################--set shape static positions--###########################*/

	TextureManager holder;
	Sprite* spritesarray = NULL;

	int counter_addshape = 0, counter_deadshape = 0, deadsliders_correction = 0, current_score = 0;
	sf::Vector2f shapeposition;

	std::vector<WrapperShape*> shapes_vec;
	std::vector<WrapperShape*>::const_iterator shape_iter;

	std::vector<WrapperShape*> static_shape_vec;
	std::vector<WrapperShape*> shape_track1_vec;
	std::vector<WrapperShape*> shape_track2_vec;
	std::vector<WrapperShape*> shape_track3_vec;
	std::vector<WrapperShape*> shape_track4_vec;

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

	sf::Sprite gamebackground;
	sf::Texture Backgroundtexture = TextureManager::GetTexture("Assets/temp.png");//1280x1024
	gamebackground.setTexture(Backgroundtexture);
	gamebackground.setPosition(0, 0);

	sf::Vector2f slidertrack_start_coordinates, slider_start_coordinates, endpoint_start_coordinates;
	slidertrack_start_coordinates.x = 140;
	slidertrack_start_coordinates.y = 150;
	endpoint_start_coordinates.x = 100;
	endpoint_start_coordinates.y = 600;
	slider_start_coordinates.x = 100;
	slider_start_coordinates.y = 100;

	while(counter_addshape < 8)
	{
		if (counter_addshape < 4)//assign texture and position slider track
		{
			slidertrack_start_coordinates.x = 140+ (200 * (counter_addshape % 4));
			static_shape_vec.push_back(new WrapperShape("Assets/slidertrack.png", slidertrack_start_coordinates));
		}
		else//assign texture and position slider endpoint
		{
			endpoint_start_coordinates.x = 100 + (200 * (counter_addshape % 4));
			static_shape_vec.push_back(new WrapperShape("Assets/endpoint.png", endpoint_start_coordinates));
		}
		counter_addshape++;
	}

	shape_track1_vec.push_back(new WrapperShape("Assets/slider.png", slider_start_coordinates));
	counter_addshape = 1;



	/*###########################--window loop--###########################*/
	while (window.isOpen())
	{


		/*###########################--loop for animation, limited--###########################*/
		while (gameTimeDelta_secs < time_remain)
		{
			//update clock
			gameTimeDelta = gameclock.restart();
			gameTime += gameTimeDelta;
			gameTimeDelta_secs = gameTime.asSeconds();
			new_second = floor(gameTimeDelta_secs);
			//updates every 2 seconds
			if (new_second > current_second)
			{
				//new second is the current game time rounded into a integer
				//current seconds checks if a new second has been surpassed comapairing to new second
				//for example, new second could be written as 1 second for a number of cycles, until it reaches 2 seconds in count
				//then it says a new second has been achieved, overwrite current_second and check if it's even
				//basically, for every increment of a second and if a new second acheived, check if number of seconds even and if even, 
				//add new shape if new even second achieved.
				current_second = new_second;
				if ((current_second % 2) == 0)
				{//every 2 seconds, add a new shape slider
					switch (counter_addshape % 4)
					{
					case 0:
						slider_start_coordinates.x = 100 + (200 * (0));
						shape_track1_vec.push_back(new WrapperShape("Assets/slider.png", slider_start_coordinates));//spawn on the next track
						break;
					case 1:
						slider_start_coordinates.x = 100 + (200 * (1));
						shape_track2_vec.push_back(new WrapperShape("Assets/slider.png", slider_start_coordinates));//spawn on the next track
						break;
					case 2:
						slider_start_coordinates.x = 100 + (200 * (2));
						shape_track3_vec.push_back(new WrapperShape("Assets/slider.png", slider_start_coordinates));//spawn on the next track
						break;
					case 3:
						slider_start_coordinates.x = 100 + (200 * (3));
						shape_track4_vec.push_back(new WrapperShape("Assets/slider.png", slider_start_coordinates));//spawn on the next track
						break;
					}
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
			//update all shapes and 
			//find all dead shapes
			counter_deadshape = 0;

			shapes_vec.clear();
			shapes_vec.insert(shapes_vec.end(), shape_track1_vec.begin(), shape_track1_vec.end());
			shapes_vec.insert(shapes_vec.end(), shape_track2_vec.begin(), shape_track2_vec.end());
			shapes_vec.insert(shapes_vec.end(), shape_track3_vec.begin(), shape_track3_vec.end());
			shapes_vec.insert(shapes_vec.end(), shape_track4_vec.begin(), shape_track4_vec.end());
			//must change position
			for (shape_iter = shapes_vec.begin(); shape_iter != shapes_vec.end(); ++shape_iter)
			{
				shapeposition = (*shape_iter)->getPosition();
				shapeposition.y += shapespeed;
				(*shape_iter)->setPosition(shapeposition);
				if (shapeposition.y >= 605)
				{
					(*shape_iter)->killShape();
				}
				counter_deadshape++;
			}//slider_vec_position
			//dead sliders clear
			deadsliders_correction = 0;
			if (!shape_track1_vec.empty())
			{
				for (int i = 0; i < shape_track1_vec.size(); i++)
				{
					if (shape_track1_vec.at(i)->checkAlive() == false)
					{
						shape_track1_vec.erase(shape_track1_vec.begin() + i);
						i--;
					}
				}
			}
			if (!shape_track2_vec.empty())
			{
				for (int i = 0; i < shape_track2_vec.size(); i++)
				{
					if (shape_track2_vec.at(i)->checkAlive() == false)
					{
						shape_track2_vec.erase(shape_track2_vec.begin() + i);
						i--;
					}
				}
			}
			if (!shape_track3_vec.empty())
			{
				for (int i = 0; i < shape_track3_vec.size(); i++)
				{
					if (shape_track3_vec.at(i)->checkAlive() == false)
					{
						shape_track3_vec.erase(shape_track3_vec.begin() + i);
						i--;
					}
				}
			}
			if (!shape_track4_vec.empty())
			{
				for (int i = 0; i < shape_track4_vec.size(); i++)
				{
					if (shape_track4_vec.at(i)->checkAlive() == false)
					{
						shape_track4_vec.erase(shape_track4_vec.begin() + i);
						i--;
					}
				}
			}
			/*
			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == Event::KeyPressed) {
					//Close window
					if (event.key.code == sf::Keyboard::Escape) window.close();

					//Input
					if (event.key.code == sf::Keyboard::A) {
						tempshape = track_one.pop_front();
						if(shape_track1_vec.at())
						current_score += score_manager.getScore(tempShape.getPosition());
					}
					else if (event.key.code == sf::Keyboard::S) {
						tempshape = track_two.pop_front();
						current_score += score_manager.getScore(tempShape.getPosition());
					}
					else if (event.key.code == sf::Keyboard::D) {
						tempshape = track_three.pop_front();
						current_score += score_manager.getScore(tempShape.getPosition());
					}
					else if (event.key.code == sf::Keyboard::F) {
						tempshape = track_four.pop_front();
						current_score += score_manager.getScore(tempShape.getPosition());
					}
				}
			}*/

			//draw all shapes/sprirtes objects------------------------------------------
			window.clear();

			window.setView(mainView);

			window.draw(gamebackground);

			shapes_vec.clear();
			shapes_vec.insert(shapes_vec.end(), static_shape_vec.begin(), static_shape_vec.end());
			shapes_vec.insert(shapes_vec.end(), shape_track1_vec.begin(), shape_track1_vec.end());
			shapes_vec.insert(shapes_vec.end(), shape_track2_vec.begin(), shape_track2_vec.end());
			shapes_vec.insert(shapes_vec.end(), shape_track3_vec.begin(), shape_track3_vec.end());
			shapes_vec.insert(shapes_vec.end(), shape_track4_vec.begin(), shape_track4_vec.end());

			for (shape_iter = shapes_vec.begin(); shape_iter != shapes_vec.end(); shape_iter++)
			{
				window.draw((*shape_iter)->getSprite());
			}

			window.display();
			//close window if esc pressed
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			{
				gameTimeDelta_secs = gameTimeDelta_secs + time_remain;
				window.close();
			}

		}//time loop end
		if (gameTimeDelta_secs >= time_remain)
		{
			window.close();
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}
		window.clear();

		window.setView(mainView);

		window.draw(gamebackground);
	}//new loop stuff end
}//method end