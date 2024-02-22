#include "BoxOfDonuts.h"

#include <iostream>

BoxOfDonuts::BoxOfDonuts()
{
    // TODO: Implement random for number of donuts
}

BoxOfDonuts::~BoxOfDonuts()
{}

// Shows the description of the item
void BoxOfDonuts::ShowDescription() const
{
    if (count > 0)
    {
        std::cout << "There is a box of donuts. It has " << count << " donuts in it." << std::endl;
    }
    else
    {
        std::cout << "There is a box of donuts. It is empty." << std::endl;
    }
}

// Eat one donut from the box
void BoxOfDonuts::Use()
{
    std::cout << "You ate a donut." << std::endl;
    count--;
}
