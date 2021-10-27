#ifndef LAB1_HERO_H
#define LAB1_HERO_H

#include <iostream>
#include <fstream>
#include "Heroes.h"

class Hero : public Heroes{
public:
    Hero();
    Hero(std::string _name, std::string _weaponType);
    Hero(const Hero& hero);
    ~Hero();
    void printInfo() override;
    void changeInfo() override;
    void saveToFile(std::ofstream& _output) override;
    void getFromFile(std::ifstream& _input) override;
    void setName(std::string _name) override;
    std::string getName() override;
    void setWeapon(std::string _weapon);
    std::string getWeapon();
    void setAbility(std::string _ability);
    std::string* getAbility();
    void setTempAbility(int _tempAbility);
    int getTempAbility();
    void setAbilitySize(int _abilitySize);
    int getAbilitySize();
private:
    std::string name;
    std::string weaponType;
    std::string* abilities;
    int tempAbility = 0;
    int abilitySize;
};


#endif //LAB1_HERO_H
