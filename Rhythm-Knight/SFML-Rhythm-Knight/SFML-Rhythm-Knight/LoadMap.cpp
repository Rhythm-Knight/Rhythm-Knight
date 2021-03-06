#include "stdafx.h"
#include "Engine.h"

void Engine::loadMap()
{
	m_Playing = false;

	// Delete the previously allocated memory
	for (int i = 0; i < m_LM.getMainAreaSize().y; ++i)
	{
		delete[] m_ArrayLevel[i];

	}
	delete[] m_ArrayLevel;

	// Load the next 2d array with the map for the level
	// And repopulate the vertex array as well
	m_ArrayLevel = m_LM.nextLevel(m_VALevel);

}