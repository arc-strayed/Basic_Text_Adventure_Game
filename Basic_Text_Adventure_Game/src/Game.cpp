#include <iostream>
#include "Game.h"

Game::Game()
{
    player = new Player();
    command = new String("");

    player_position = { 0, 0 };

    // Instantiate rooms
    Room* rooms = new Room[MAP_SIZE * MAP_SIZE];
    for (int i = 0; i < MAP_SIZE * MAP_SIZE; i += MAP_SIZE)
    {
        for (int j = 0; j < MAP_SIZE; j++)
        {
            rooms[i * MAP_SIZE + j] = Room();
        }
    }

    running = true;
}

Game::~Game()
{
    delete player;
    delete command;
    delete[] rooms;

    player = nullptr;
    command = nullptr;
    rooms = nullptr;
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
    int x_position = player_position.x + x;
    int y_position = player_position.y + y;

    if (x_position < 0 || x_position > MAP_SIZE - 1 ||
        y_position < 0 || y_position > MAP_SIZE - 1)
    {
        std::cout << "There is no room there." << std::endl;
    }
    else
    {
        std::cout << "You moved to " << player_position.x << ", " << player_position.y << std::endl;
    }
}
