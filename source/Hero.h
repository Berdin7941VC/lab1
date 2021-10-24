#ifndef LAB1_HERO_H
#define LAB1_HERO_H

#include <iostream>
#include "Heroes.h"

class Hero : public Heroes{
public:
    Hero();
    std::string getName() override;
    void setName(std::string _name) override;
    std::string getWeapon();
    void setWeapon(std::string _weapon);
    std::string* getAbility();
    void setAbility(std::string _ability);
    void printInfo() override;
private:
    std::string name;
    std::string weaponType;
    std::string* abilities;
    int tempAbility = 0;
    int abilitySize;
};


#endif //LAB1_HERO_H
