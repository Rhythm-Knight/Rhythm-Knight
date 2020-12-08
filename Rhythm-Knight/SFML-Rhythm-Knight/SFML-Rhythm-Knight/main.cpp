#include <iostream>
#include "SceneManager.h"
#include "Engine.h"

int main()
{
    SceneManager* s1 = new SceneManager();
    //s1->dispBattle();
    Engine engine;

    // Start the engine
    engine.run();
}