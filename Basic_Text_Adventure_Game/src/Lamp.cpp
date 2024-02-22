#include "Lamp.h"

#include <iostream>

Lamp::Lamp()
{}

Lamp::~Lamp()
{}

// Shows the description of the item
void Lamp::ShowDescription() const
{
    if (turned_on)
    {
        std::cout << "There is a lamp. The lamp is lit. It lights up the room to reveal nothing." << std::endl;
    }
    else
    {
        std::cout << "There is a lamp. The lamp is unlit." << std::endl;
    }
}

// Turns the lamp on or off
void Lamp::Use()
{
    turned_on = !turned_on;

    if (turned_on)
    {
        std::cout << "You lit the lamp." << std::endl;
    }
    else
    {
        std::cout << "You blow out the lamp." << std::endl;
    }
}