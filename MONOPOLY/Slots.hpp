#ifndef SLOT_HPP
#define SLOT_HPP

#include <string>
#include <vector>
#include "Property.hpp"

class Slot {
public:
    virtual void landOn(Player& player) = 0;
    virtual std::string getType() const = 0;
    virtual ~Slot() {}
};

class PropertySlot : public Slot {
private:
    Property property;

public:
    PropertySlot(const Property& property);
    
    void landOn(Player& player) override;
    std::string getType() const override;
    Property& getProperty();
};

class TrainSlot : public Slot {
private:
    std::string name;
    int price;
    int owner; // Index of player who owns this train slot
    bool available;

public:
    TrainSlot(std::string name, int price);
    
    void landOn(Player& player) override;
    std::string getType() const override;
    void setOwner(int playerIndex);
    int getOwner() const;
};

class SurpriseSlot : public Slot {
public:
    void landOn(Player& player) override;
    std::string getType() const override;
};

class FreeParkingSlot : public Slot {
public:
    void landOn(Player& player) override;
    std::string getType() const override;
};

class TaxSlot : public Slot {
public:
    void landOn(Player& player) override;
    std::string getType() const override;
};

class JailSlot : public Slot {
public:
    void landOn(Player& player) override;
    std::string getType() const override;
};

class WaterElectricitySlot : public Slot {
private:
    std::string type; // "Water" or "Electricity"
    int price;
    int owner; // Index of player who owns this slot
    bool available;

public:
    WaterElectricitySlot(std::string type, int price);
    
    void landOn(Player& player) override;
    std::string getType() const override;
    void setOwner(int playerIndex);
    int getOwner() const;
};

#endif // SLOT_HPP
