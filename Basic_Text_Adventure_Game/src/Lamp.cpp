#include "Lamp.h"

#include <iostream>

Lamp::Lamp()
{}

Lamp::~Lamp()
{}

// Shows the description of the item
void Lamp::ShowDescription()
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
}