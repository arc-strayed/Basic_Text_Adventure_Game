#include "Room.h"

Room::Room()
{

}

Room::Room(const std::string& description, Item* item)
{
    Room_Description = description;
    room_item = item;
}

Room::~Room()
{

}

void Room::ShowDescription() const
{

}
