
#ifndef LAB1_ENEMY_H
#define LAB1_ENEMY_H

#include <iostream>
#include <fstream>
#include "Heroes.h"

class Enemy : public Heroes{
public:
    Enemy();
    Enemy(std::string _name, std::string _weaponType, std::string _crimeType, std::string _habitat);
    Enemy(const Enemy& enemy);
    ~Enemy();
    void printInfo() override;
    void changeInfo() override;
    void saveToFile(std::ofstream& _output) override;
    void getFromFile(std::ifstream& _input) override;
    void setName(std::string _name) override;
    std::string getName() override;
    void setWeapon(std::string _weapon);
    std::string getWeapon();
    void setCrimeType(std::string _crime);
    std::string getCrimeType();
    void setHabitat(std::string _habitat);
    std::string getHabitat();
    void setAbility(std::string _ability);
    std::string* getAbility();
    void setTempAbility(int _tempAbility);
    int getTempAbility();
    void setAbilitySize(int _abilitySize);
    int getAbilitySize();
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
