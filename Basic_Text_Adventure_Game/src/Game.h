#pragma once
#include <StringUtil.h>
#include "Player.h"
#include "Room.h"
#include "Lamp.h"
#include "BoxOfDonuts.h"
#include "Cat.h"

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
    void Render();

    bool IsRunning() const { return running; };

    void MovePlayer(int x, int y);
private:
    Player* player = nullptr;
    String* command = nullptr;
    Item* items[3] = { new Lamp(), new BoxOfDonuts(), new Cat() };

    const int MAP_SIZE = 10;
    Room rooms[10][10] = {};

    char screen[12][12] = {};

    Position2D player_position;

    bool running = false;
};