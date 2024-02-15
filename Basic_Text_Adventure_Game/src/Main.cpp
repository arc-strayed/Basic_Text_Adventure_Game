#include <iostream>
#include <string>
#include "Game.h"

int main()
{
    Game* game = new Game();

    while (game->IsRunning())
    {
        game->HandleInput();
    }

    return 0;
}