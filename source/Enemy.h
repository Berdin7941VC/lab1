
#ifndef LAB1_ENEMY_H
#define LAB1_ENEMY_H

#include <iostream>
#include "Heroes.h"

class Enemy : public Heroes{
public:
    Enemy();
    void setName(std::string _name) override;
    std::string getName() override;
    void printInfo() override;
    void setWeapon(std::string _weapon);
    std::string getWeapon();
    void setCrimeType(std::string _crime);
    std::string getCrimeType();
    void setHabitat(std::string _habitat);
    std::string getHabitat();
    void setAbility(std::string _ability);
    std::string* getAbility();

private:
    std::string name;
    std::string weaponType;
    std::string crimeType;
    std::string habitat;
    std::string* abilities;
    int tempAbility = 0;
    int abilitySize;
};


#endif //LAB1_ENEMY_H
