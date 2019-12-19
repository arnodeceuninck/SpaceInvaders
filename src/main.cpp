#include <iostream>
#include "Game.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::shared_ptr<spaceinvaders::Game> game = std::make_shared<spaceinvaders::Game>();
    return 0;
}