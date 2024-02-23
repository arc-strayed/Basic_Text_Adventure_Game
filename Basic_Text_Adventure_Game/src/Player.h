#pragma once

#include <vector>
#include <StringUtil.h>

class Player
{
public:
    Player();
    ~Player();

    bool FindSpell(const String& name);
private:

    std::vector<String*> spells = { new String("eclipse"), new String("explode"), new String("portal"), new String("sigmund's clairvoyance") };
};