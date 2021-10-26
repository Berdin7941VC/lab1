#ifndef LAB1_HERO_H
#define LAB1_HERO_H

#include <iostream>
#include <fstream>
#include "Heroes.h"

struct HeroData{
    std::string _name;
    std::string _weaponType;
};

class Hero : public Heroes{
public:
    Hero();
    std::string getName() override;
    void setName(std::string _name) override;
    void printInfo() override;
    void saveToFile(std::ofstream& _output) override;
    void getFromFile(std::ifstream& _input) override;
    std::string getWeapon();
    void setWeapon(std::string _weapon);
    std::string* getAbility();
    void setAbility(std::string _ability);
private:
    std::string name;
    std::string weaponType;
    std::string* abilities;
    int tempAbility = 0;
    int abilitySize;
};


#endif //LAB1_HERO_H
