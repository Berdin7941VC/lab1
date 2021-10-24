#include "Hero.h"

Hero::Hero() {
    abilities = new std::string[10];
    abilitySize = 10;
}

std::string Hero::getName() {
    return this->name;
}

void Hero::setName(std::string _name) {
    this->name = _name;
}

std::string Hero::getWeapon() {
    return this->weaponType;
}

void Hero::setWeapon(std::string _weapon) {
    this->weaponType = _weapon;
}

std::string* Hero::getAbility() {
    return this->abilities;
}

void Hero::setAbility(std::string _ability) {
    if(tempAbility == abilitySize-1){
        abilities[tempAbility] = _ability;
        std::string* newAbility = new std::string[abilitySize+10];
        for(int i=0;i<tempAbility;i++)
            newAbility[i] = abilities[i];
        delete[] abilities;
        abilities = newAbility;
        abilitySize += 10;
    }
    else{
        abilities[tempAbility] = _ability;
        tempAbility++;
    }
}

void Hero::printInfo() {
    std::cout << "Hero name: " << this->name << "\n";
    std::cout << "Hero weapon type: " << this->weaponType << "\n";
    if(tempAbility == 1)
        std::cout << "Hero ability: " << this->abilities[0] << "\n\n";
    else {
        std::cout << "Hero abilities: " << this->abilities[0] << ", ";
        for (int i = 1; i < tempAbility - 1; i++)
            std::cout << abilities[i] << ", ";
        std::cout << abilities[tempAbility - 1] << "\n\n";
    }
}