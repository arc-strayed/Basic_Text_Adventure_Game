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

    void ShowDescription() const;
private:
    std::string Room_Description;
};