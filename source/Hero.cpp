#include "Hero.h"

Hero::Hero() {
    std::cout << "Object Hero. Call simple constructor\n";
    this->abilities = new std::string[10];
    this->abilitySize = 10;
}

Hero::Hero(std::string _name, std::string _weaponType) : name(_name), weaponType(_weaponType) {
    std::cout << "Object Hero. Call constructor with parameters\n" << std::endl;
    this->abilities = new std::string[10];
    this->abilitySize = 10;
}


Hero::Hero(const Hero &hero) : name(hero.name), weaponType(hero.weaponType), tempAbility(hero.tempAbility),
                               abilitySize(hero.abilitySize), abilities(hero.abilities) {
    std::cout << "Object Hero. Call Copy constructor\n";
}

Hero::~Hero() {
    std::cout << "Object Hero. Call destructor\n";
    delete[] this->abilities;
}

void Hero::printInfo() {
    std::cout << "Hero name: " << this->name << "\n";
    std::cout << "Hero weapon type: " << this->weaponType << "\n";
    if (this->tempAbility == 1)
        std::cout << "Hero ability: " << this->abilities[0] << "\n\n";
    else {
        std::cout << "Hero abilities: " << this->abilities[0] << ", ";
        for (int i = 1; i < this->tempAbility - 1; i++)
            std::cout << this->abilities[i] << ", ";
        std::cout << this->abilities[tempAbility - 1] << "\n\n";
    }
}

void Hero::changeInfo() {
    int choicer;
    std::cout << "Old name: " << this->name << "\n";
    std::cout << "New name: ";
    std::cin >> this->name;
    std::cout << "\nOld weapon type: " << this->weaponType << "\n";
    std::cout << "New weapon type: ";
    std::cin >> this->weaponType;
    for (int i = 0; i < this->tempAbility; i++) {
        std::string temp;
        std::cout << "\nOld " << i + 1 << " ability: " << this->abilities[i] << "\n";
        std::cout << "\nNew " << i + 1 << " ability: ";
        std::cin >> temp;
        this->abilities[i] = temp;
    }
    while (true) {
        std::cout << "Want to add a new ability?\n1 - Yes, 2 - No\nEnter a number: ";
        std::cin >> choicer;
        if (choicer == 1) {
            std::string temp;
            std::cout << "\nEnter ability: ";
            std::cin >> temp;
            setAbility(temp);
            std::cout << "\n";
        } else
            break;
    }
}

void Hero::saveToFile(std::ofstream &_output) {
    _output << "1\n";
    _output << this->name << "\n";
    _output << this->weaponType << "\n";
    _output << this->tempAbility << "\n";
    _output << this->abilitySize << "\n";
    for (int i = 0; i < this->tempAbility; i++)
        _output << this->abilities[i] << "\n";
}

void Hero::getFromFile(std::ifstream &_input) {
    std::string temp;
    int abilityNumber = 0;
    std::getline(_input, temp);
    this->name = temp;
    std::getline(_input, temp);
    this->weaponType = temp;
    std::getline(_input, temp);
    abilityNumber = std::stoi(temp);
    std::getline(_input, temp);
    this->abilitySize = std::stoi(temp);
    for (int i = 0; i < abilityNumber; i++) {
        std::getline(_input, temp);
        setAbility(temp);
    }
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

std::string *Hero::getAbility() {
    return this->abilities;
}

void Hero::setAbility(std::string _ability) {
    if (this->tempAbility == this->abilitySize - 1) {
        this->abilities[this->tempAbility] = _ability;
        std::string *newAbility = new std::string[this->abilitySize + 10];
        for (int i = 0; i < this->tempAbility; i++)
            newAbility[i] = this->abilities[i];
        delete[] this->abilities;
        this->abilities = newAbility;
        this->abilitySize += 10;
    } else {
        this->abilities[this->tempAbility] = _ability;
        this->tempAbility++;
    }
}

void Hero::setTempAbility(int _tempAbility) {
    this->tempAbility = _tempAbility;
}

int Hero::getTempAbility() {
    return this->tempAbility;
}

void Hero::setAbilitySize(int _abilitySize) {
    this->abilitySize = _abilitySize;
}

int Hero::getAbilitySize() {
    return this->abilitySize;
}
