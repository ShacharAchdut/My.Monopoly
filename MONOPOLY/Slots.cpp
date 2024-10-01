#include "Slots.hpp"


// Default constructor
Slots::Slots() : kind(nullptr){}

// Constructor with vertices and kind of the Slots
Slots::Slots(int index, kindSlots* kindSlotsType,std::string color)
        : index(index), kind(kindSlotsType), color(color) {}


// Getter for Vertexs
int Slots::getIndex()
{
    return index;
}
std::string Slots::getColor()
{
    return color;
}
kindSlots *Slots::getKind()
{
    return kind;
}
std::string Slots::getKindAsString()
{
    // Check what the type of the Slots (Street, Train, Utility, Go, ect...)
    if (dynamic_cast<Street*>(kind) != nullptr)
    {
        return "Street";
    }
    if (dynamic_cast<Train*>(kind) != nullptr)
    {
        return "Train";
    }
    if (dynamic_cast<Utility*>(kind) != nullptr)
    {
        return "Utility";
    }
    if (dynamic_cast<Go*>(kind) != nullptr)
    {
        return "Go";
    }
    if (dynamic_cast<Jail*>(kind) != nullptr)
    {
        return "Jail";
    }
    if (dynamic_cast<Chance*>(kind) != nullptr)
    {
        return "Chance";
    }
    if (dynamic_cast<CommunityChest*>(kind) != nullptr)
    {
        return "CommunityChest";
    }
    if (dynamic_cast<FreeParking*>(kind) != nullptr)
    {
        return "FreeParking";
    }
    if (dynamic_cast<Tax*>(kind) != nullptr)
    {
        return "Tax";
    }
    if (dynamic_cast<GoToJail*>(kind) != nullptr)
    {
        return "GoToJail";
    }

    // If the kind doesn't match any of the known types, return "Unknown"
    return "Unknown";
}
bool Slots::isPurchasable()
{
    std::string SlotsString = getKindAsString();

    // Check if the Slots is a Street, Train, or Utility (purchasable types)
    if (SlotsString == "Street" || SlotsString == "Train" || SlotsString == "Utility")
    {
        return true; // The Slots is purchasable
    }

    return false; // The Slots is not purchasable
}