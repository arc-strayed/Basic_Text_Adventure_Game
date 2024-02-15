#pragma once

class Item
{
public:
    virtual void ShowDescription() const = 0;
    virtual void Use() = 0;
};