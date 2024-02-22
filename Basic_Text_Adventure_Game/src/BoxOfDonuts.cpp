#include "BoxOfDonuts.h"

#include <iostream>

BoxOfDonuts::BoxOfDonuts()
{
    // TODO: Implement random for number of donuts
}

BoxOfDonuts::~BoxOfDonuts()
{}

void BoxOfDonuts::ShowDescription()
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

void BoxOfDonuts::Use()
{
    std::cout << "You ate a donut." << std::endl;
    count--;
}
