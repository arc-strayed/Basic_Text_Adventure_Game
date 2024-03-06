#include <iostream>
#include "Game.h"

Game::Game()
{
    player = new Player();
    command = new String("");

    player_position = { 0, 0 };

    // Create rooms
    for (int column = 0; column < MAP_SIZE; column++)
    {
        for (int row = 0; row < MAP_SIZE; row++)
        {
            rooms[column][row] = Room();
        }
    }

    // Fill screen
    for (int column = 0; column < 12; column++)
    {
        for (int row = 0; row < 12; row++)
        {
            screen[column][row] = '.';
        }
    }

    // Rooms
    rooms[2][0] = Room("You are in a dark room.", items[0]);

    rooms[2][5] = Room("You are in a room with a table.", items[1]);

    rooms[4][7] = Room("You are in a room with a creature.", items[2]);

    rooms[2][8] = Room("You are in a room with a barrel.", items[3]);

    // Intro message
    std::cout << "You find yourself in an unfamiliar place with a series of rooms.\n(Type \"help\" for commands)" << std::endl;

    // Map
    Render();

    // Game
    running = true;
}

Game::~Game()
{
    // Clean up
    delete player;
    delete command;
    
    for (int i = 0; i < 3; i++)
    {
        delete items[i];
    }

    player = nullptr;
    command = nullptr;
}

// Handles player input
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
    if (command->EqualTo("move north"))
    {
        MovePlayer(0, -1);
        rooms[player_position.x][player_position.y].ShowDescription();
    }
    if (command->EqualTo("move south"))
    {
        MovePlayer(0, 1);
        rooms[player_position.x][player_position.y].ShowDescription();
    }
    if (command->EqualTo("move west")) 
    {
        MovePlayer(-1, 0);
        rooms[player_position.x][player_position.y].ShowDescription();
    }
    if (command->EqualTo("move east")) 
    {
        MovePlayer(1, 0);
        rooms[player_position.x][player_position.y].ShowDescription();
    }
    
    // Show room description
    if (command->EqualTo("description"))
    {
        rooms[player_position.x][player_position.y].ShowDescription();
    }

    // Use item
    if (command->EqualTo("use item"))
    {
        Item* item = rooms[player_position.x][player_position.y].room_item;

        if (item) item->Use();
    }

    // Find a spell
    if (command->Find("spell ") >= 0)
    {
        command->Replace("spell ", "");

        if (player->FindSpell(*command))
        {
            std::cout << "You have that spell." << std::endl;
        }
        else
        {
            std::cout << "You don't have that spell!" << std::endl;
        }
    }

    // Print out help information
    if (command->EqualTo("help") || command->EqualTo("h"))
    {
        std::cout << "Possible commands:\nquit\nmove north\nmove south\nmove west\nmove east\ndescription\nuse item\nspell (x)\nhelp\n";
    }

    std::cout << std::endl;
}

// Renders a map to the console
void Game::Render()
{
    // Add borders and clear screen
    for (int column = 0; column < 12; column++)
    {
        for (int row = 0; row < 12; row++)
        {
            if (column == 0 || column == 11)
            {
                screen[column][row] = '|';
            }
            else if (row == 0 || row == 11)
            {
                screen[column][row] = '-';
            }
            else
            {
                screen[column][row] = '.';
            }
        }
    }

    // Set player's position on map
    screen[player_position.x + 1][player_position.y + 1] = '@';

    // Print map to console
    for (int row = 0; row < 12; row++)
    {
        for (int column = 0; column < 12; column++)
        {
            // Sets color to black for map
            std::cout << "\x1b[1;30m";

            // Color player's character bright yellow
            if (column == player_position.x + 1 && row == player_position.y + 1)
            {
                std::cout << "\x1b[0m";
                std::cout << "\x1b[1;33m";
            }

            // Draw character
            std::cout << screen[column][row];

            // Fill borders and spaces
            if (row == 0 && column < 11 || row == 11 && column < 11)
            {
                std::cout << '-';
            }
            else
            {
                std::cout << ' ';
            }

            // Reset coloring
            std::cout << "\x1b[0m";
        }

        // Move to next line
        std::cout << '\n';
    }

    std::cout << std::endl;
}

// Moves the player
void Game::MovePlayer(int x, int y)
{
    int x_position = player_position.x + x;
    int y_position = player_position.y + y;

    if (x_position < 0 || x_position > MAP_SIZE - 1 ||
        y_position < 0 || y_position > MAP_SIZE - 1)
    {
        std::cout << "There is no room there.\n" << std::endl;
    }
    else
    {
        player_position.x = x_position;
        player_position.y = y_position;
        std::cout << "You moved to " << player_position.x << ", " << player_position.y << '\n' << std::endl;
    }
}
