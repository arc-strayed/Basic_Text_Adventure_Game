#include "Room.h"

#include <iostream>

Room::Room()
{
    Room_Description = "Empty room.";
}

Room::Room(const std::string& description, Item* item)
{
    Room_Description = description;

    room_item = item;
}

Room::~Room()
{
    if (room_item)
    {
        //delete room_item;
        room_item = nullptr;
    }
}

// Show description of room
void Room::ShowDescription() const
{
    if (!Room_Description.empty())
    {
        std::cout << Room_Description << std::endl;

        if (room_item)
        {
            room_item->ShowDescription();
        }
    }
}
}
