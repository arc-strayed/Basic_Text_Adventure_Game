#include "Player.h"

#include <algorithm>
#include <iostream>

Player::Player()
{
    spells = { new String("eclipse"), new String("explode"), new String("portal"), new String("sigmund's clairvoyance") };
}

Player::~Player()
{
    for (int i = 0; i < 4; i++)
    {
        delete spells[i];
    }
}

// Finds a spell using binary search
bool Player::FindSpell(const String& name)
{
    int start_index = 0;
    int end_index = 3;

    while (start_index <= end_index)
    {
        int iterator = (start_index + end_index) / 2;

        if (*spells[iterator] == name)
            return true;

        if (*spells[iterator] < name)
            start_index = iterator + 1;
        else
            end_index = iterator - 1;
    }

    return false;
}