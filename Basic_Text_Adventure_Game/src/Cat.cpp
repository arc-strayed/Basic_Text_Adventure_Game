#include "Cat.h"

#include <iostream>

Cat::Cat()
{}

Cat::~Cat()
{}

// Shows the description of the item
void Cat::ShowDescription()
{
    if (purring)
    {
        std::cout << "There is a cat. It is currently purring." << std::endl;
    }
    else
    {
        std::cout << "There is a cat." << std::endl;
    }
}

// Pet the cat
void Cat::Use()
{
    purring = !purring;

    if (purring)
    {
        std::cout << "You stop petting the cat." << std::endl;
    }
    else
    {
        std::cout << "You start petting the cat." << std::endl;
    }
}
