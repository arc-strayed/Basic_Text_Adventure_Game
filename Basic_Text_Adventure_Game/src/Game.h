#pragma once
#include <StringUtil.h>
#include "Player.h"
#include "Room.h"
#include "Lamp.h"
#include "BoxOfDonuts.h"
#include "Cat.h"
#include "ExplosiveBarrel.h"
#include "Compass.h"

struct Position2D // Simple struct for holding x and y position
{
    int x;
    int y;
};

class Game
{
public:
    Game();
    ~Game();

    void HandleInput(); // Handles player input
    void Render(); // Renders a map to the console

    bool IsRunning() const { return running; };

    void MovePlayer(int x, int y); // Moves the player

private:
    // Game
    bool running = false;

    // Player
    Player* player = nullptr;
    Position2D player_position;
    String* command = nullptr;

    const char compass_ascii[40] = "   N   \n   |  \nW --- E\n   |  \n   S   \n\n"; // Compass
    bool has_compass = false;

    // Room
    const int MAP_SIZE = 10;
    Room rooms[10][10] = {};
    Item* items[5] = { new Lamp(), new BoxOfDonuts(), new Cat(), new ExplosiveBarrel(&running), new Compass(&has_compass)};

    // Map
    char screen[12][12] = {};

};