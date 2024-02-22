#include <iostream>
#include "Game.h"

Game::Game()
{
    player = new Player();
    command = new String("");


    running = true;
}

Game::~Game()
{
    delete player;
    delete command;

    player = nullptr;
    command = nullptr;
}

void Game::HandleInput()
{
    std::cout << "$: ";
    command->ReadFromConsole();
    command->ToLower();

    // Handle command
    if (command->EqualTo("quit") == true || command->EqualTo("q") == true)
    {
        running = false;
    }
}