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

void Game::HandleInput()
{
    std::cout << "Enter a command: ";
    command->ReadFromConsole();
    command->ToLower();

    if (command->EqualTo("quit") == true || command->EqualTo("q") == true)
    {
        running = false;
    }
}