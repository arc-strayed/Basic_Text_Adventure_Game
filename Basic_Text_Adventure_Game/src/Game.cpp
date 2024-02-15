#include "Game.h"

Game::Game()
{
    player = new Player();
    command = new String();

    running = true;
}

Game::~Game()
{
    delete player;
    delete command;

    player = nullptr;
    command = nullptr;
}
