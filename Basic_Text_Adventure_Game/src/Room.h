#pragma once

#include <string>
#include "Item.h"

class Room
{
public:
    Room();
    Room(const std::string& description, Item* item);
    ~Room();

    Item* room_item = nullptr;

    void ShowDescription() const; // Show description of room

private:
    std::string Room_Description;

};