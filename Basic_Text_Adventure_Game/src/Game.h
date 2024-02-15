#pragma once
#include "Player.h"
#include "Room.h"

class Game
{
public:
    Game();
    ~Game();

    bool IsRunning() const { return running; };
private:
    Player* player = nullptr;
    Room rooms[10][10];

    bool running = false;
};