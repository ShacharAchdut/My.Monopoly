#ifndef Slots_HPP
#define Slots_HPP
#include "KindOfSlot.hpp"

    class Slots
    {
    private:
        kindOfSlots* kind; // Pointer to base class to support polymorphism
        int index;
        std::string color;

    public:
        virtual ~Slots() {} // Add a virtual destructor
        int numberOfHouses = 0;
        std::string ownerColor = "None";
        Slots();
        Slots(int index, KindOfSlot* kind,std::string color);
        std::string getColor();
        int getIndex();
        KindOfSlot* getKind();
        bool isPurchasable();
        std::string getKindAsString();
    };

#endif //Slots_HPP