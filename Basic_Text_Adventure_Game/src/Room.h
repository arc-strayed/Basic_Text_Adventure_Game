#pragma once

#include <string>
#include "Item.h"

class Room
{
public:
    Item* room_item = nullptr;

    Room();
    Room(const std::string& description, Item* item);
    ~Room();

    // Show description of room
    void ShowDescription() const;
    // Use item in room
    void Use() const;
private:
    std::string Room_Description;
};