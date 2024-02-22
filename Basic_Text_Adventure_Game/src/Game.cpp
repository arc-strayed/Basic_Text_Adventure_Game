#include <iostream>
#include "Game.h"
#include "Lamp.h"

Lamp lamp = Lamp();

Game::Game()
{
    player = new Player();
    command = new String("");

    player_position = { 0, 0 };

    // Instantiate rooms
    for (int column = 0; column < MAP_SIZE; column++)
    {
        for (int row = 0; row < MAP_SIZE; row++)
        {
            rooms[column][row] = Room();
        }
    }
    {
    }

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

    // Handle quitting
    if (command->EqualTo("quit") == true || command->EqualTo("q") == true)
    {
        running = false;
    }

    // Movement
    if (command->EqualTo("move north"))  MovePlayer( 0, -1);
    if (command->EqualTo("move south"))  MovePlayer( 0,  1);
    if (command->EqualTo("move west"))   MovePlayer(-1,  0);
    if (command->EqualTo("move east"))   MovePlayer( 1,  0);
    
    // Show room description
    if (command->EqualTo("description"))
    {
        rooms[0][0].ShowDescription();
    }

    // Use item
    if (command->EqualTo("use item"))
    {
        Item* item = rooms[player_position.x][player_position.y].room_item;

        if (item)
        {
            item->Use();
        }
    }

    std::cout << std::endl;
}
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
        player_position.x += x;
        player_position.y += y;
        std::cout << "You moved to " << player_position.x << ", " << player_position.y << std::endl;
    }
}
