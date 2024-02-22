#include <iostream>
#include "Game.h"

Game::Game()
{
    player = new Player();
    command = new String("");

    player_position = { 0, 0 };

    // Instantiate rooms

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
    if (command->EqualTo("move north")) MovePlayer( 0, -1);
    if (command->EqualTo("move south")) MovePlayer( 0,  1);
    if (command->EqualTo("move west"))  MovePlayer(-1,  0);
    if (command->EqualTo("move east"))  MovePlayer( 1,  0);

    std::cout << '\n';
}

// Moves the player on the map
void Game::MovePlayer(int x, int y)
{
    player_position.x += x;
    player_position.y += y;

    std::cout << "Player moved to " << player_position.x << ", " << player_position.y << std::endl;
}
