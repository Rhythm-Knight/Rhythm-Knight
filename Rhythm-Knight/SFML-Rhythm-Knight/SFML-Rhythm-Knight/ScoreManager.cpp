#include "ScoreManager.h"

ScoreManager::ScoreManager() {
	init();
}

void ScoreManager::init() {
	m_score = 0;
	m_poorRange = 6.0;
	m_goodRange = 4.0;
	m_perfRange = 2.0;
	m_target = 100.0;
}

void ScoreManager::resetScore() {
	m_score = 0;
}

int ScoreManager::getScore(sf::Vector2f position) {
	//Perfect
	if (withinRange(m_target - m_perfRange, m_target + m_perfRange, position.y)) {
		return 5;
		//Good
	}
	else if (withinRange(m_target - m_goodRange, m_target + m_goodRange, position.y)) {
		return 3;
		//Poor
	}
	else if (withinRange(m_target - m_poorRange, m_target + m_poorRange, position.y)) {
		return 1;
		//Miss
	}
	else {
		return 0;
	}
}

bool ScoreManager::withinRange(float lo, float hi, float x) {
	return ((x - lo) <= (hi - lo));
}