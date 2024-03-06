#include "ExplosiveBarrel.h"

#include <iostream>

ExplosiveBarrel::ExplosiveBarrel()
    : is_game_running(nullptr)
{}

ExplosiveBarrel::ExplosiveBarrel(bool* game_running)
    : is_game_running(game_running)
{}

ExplosiveBarrel::~ExplosiveBarrel()
{
    is_game_running = nullptr;
}

// Show description of the item
void ExplosiveBarrel::ShowDescription() const
{
    std::cout << "There is a red barrel." << std::endl;
}

// Causes the barrel to explode
void ExplosiveBarrel::Use()
{
    std::cout << "You light the barrel causing it to explode before you could exit.\n\n~~~~~~~~~~~~~~~~\n~ YOU ARE DEAD ~\n~~~~~~~~~~~~~~~~" << std::endl;
    *is_game_running = false;
}