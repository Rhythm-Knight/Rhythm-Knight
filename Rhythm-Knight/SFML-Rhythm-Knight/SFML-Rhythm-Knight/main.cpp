#include <iostream>
#include "Player.h"

int main() {
    Player* p1 = new Player();
    p1->spawn(5, 4, 3, 7);
    std::cout << "Player X: " << p1->getPosition().x << 
               "\nPlayer Y: " << p1->getPosition().y << std::endl;
}