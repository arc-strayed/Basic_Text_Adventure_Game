#include "Game.h"

int main()
{
    Game* game = new Game();

    while (game->IsRunning())
    {
        game->HandleInput();
        game->Render();
    }

    return 0;
}