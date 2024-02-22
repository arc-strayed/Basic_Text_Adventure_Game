#pragma once
#include <StringUtil.h>
#include "Player.h"
#include "Room.h"

struct Position2D
{
    int x;
    int y;
};

class Game
{
public:
    Game();
    ~Game();

    void HandleInput();
    bool IsRunning() const { return running; };

    void MovePlayer(int x, int y);
private:
    Player* player = nullptr;
    String* command = nullptr;

    const int MAP_SIZE = 10;
    Room* rooms = nullptr;

    Position2D player_position;

    bool running = false;
};