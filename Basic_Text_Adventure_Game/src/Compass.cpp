#include "Compass.h"

#include <iostream>

Compass::Compass()
    : picked_up(false), has_compass(nullptr)
{}

Compass::Compass(bool* compass)
    : picked_up(false), has_compass(compass)
{}

Compass::~Compass()
{
    if (has_compass) has_compass = nullptr;
}

// Show description of item
void Compass::ShowDescription() const
{
    std::cout << "There is a compass." << std::endl;
}

// Pick up compass
void Compass::Use()
{
    if (picked_up)
    {
        std::cout << "You already have the compass." << std::endl;
    }
    else
    {
        picked_up = true;
        *has_compass = true;

        std::cout << "You pick up the compass." << std::endl;
    }
}