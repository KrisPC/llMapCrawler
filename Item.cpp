#include "Item.hpp"

Item::Item(string name)
{
    this->name = name;
}

string Item::getName()
{
    return this->name;
}