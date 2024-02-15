#pragma once
#include "Player.h"
#include "Room.h"

class Game
{
public:
    Game();
    ~Game();
private:
    Player* player = nullptr;
    Room rooms[10][10];
};