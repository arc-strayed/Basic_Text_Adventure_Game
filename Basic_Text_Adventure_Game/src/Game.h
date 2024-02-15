#pragma once
#include "Player.h"
#include "Room.h"
#include "StringUtil.h"

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    bool IsRunning() const { return running; };
private:
    Player* player = nullptr;
    String* command = nullptr;

    Room rooms[10][10];
    
    bool running = false;
};