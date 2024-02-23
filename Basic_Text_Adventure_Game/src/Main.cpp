#include "Game.h"

int main()
{
    Game* game = new Game();

    while (game->IsRunning())
    {
        game->HandleInput();
        game->Render();
    }

    delete game;
    game = nullptr;

    return 0;
}