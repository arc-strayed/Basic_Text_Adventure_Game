#pragma once

#include <vector>
#include <StringUtil.h>

class Player
{
public:
    Player();
    ~Player();

    bool FindSpell(const String& name); // Finds a spell using binary search

private:
    std::vector<String*> spells;

};