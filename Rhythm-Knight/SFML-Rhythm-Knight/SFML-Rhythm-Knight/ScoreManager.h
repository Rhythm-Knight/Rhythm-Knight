#pragma once
#ifndef SCOREMANAGER_H
#define SCOREMANAGER_H
#include <SFML/Graphics.hpp>

class ScoreManager{
public:
	ScoreManager();
	void resetScore();
	int getScore(sf::Vector2f position);

private:
	int m_score;
	float m_poorRange;
	float m_goodRange;
	float m_perfRange;
	float m_target;
	void init();
	bool withinRange(float lo, float hi, float x);
};
#endif // !SCOREMANAGER_H