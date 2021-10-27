#include "Enemy.h"

Enemy::Enemy() {
    std::cout << "Object Enemy. Call simple constructor\n";
    this->abilities = new std::string[10];
    this->abilitySize = 10;
}

Enemy::Enemy(std::string _name, std::string _weaponType, std::string _crimeType, std::string _habitat) : name(_name),
                                                                                                         weaponType(
                                                                                                                 _weaponType),
                                                                                                         crimeType(
                                                                                                                 _crimeType),
                                                                                                         habitat(_habitat) {
    std::cout << "Object Enemy. Call constructor with parameters\n";
    this->abilities = new std::string[10];
    this->abilitySize = 10;
}

Enemy::Enemy(const Enemy &enemy) : name(enemy.name), weaponType(enemy.weaponType), crimeType(enemy.crimeType),
                                   habitat(enemy.habitat), abilities(enemy.abilities), tempAbility(enemy.tempAbility),
                                   abilitySize(enemy.abilitySize) {
    std::cout << "Object Enemy. Call copy constructor\n";
}

Enemy::~Enemy() {
    std::cout << "Object Enemy. Call destructor\n";
    delete[] this->abilities;
}

void Enemy::printInfo() {
    std::cout << "Enemy name: " << this->name << "\n";
    std::cout << "Enemy weapon type: " << this->weaponType << "\n";
    std::cout << "Enemy crime: " << this->crimeType << "\n";
    std::cout << "Enemy habitat: " << this->habitat << "\n";
    if (this->tempAbility == 1)
        std::cout << "Enemy ability: " << this->abilities[0] << "\n\n";
    else {
        std::cout << "Enemy abilities: " << this->abilities[0] << ", ";
        for (int i = 1; i < this->tempAbility - 1; i++)
            std::cout << this->abilities[i] << ", ";
        std::cout << this->abilities[tempAbility - 1] << "\n\n";
    }
}

void Enemy::changeInfo() {
    int choicer;
    std::cout << "Old name: " << this->name << "\n";
    std::cout << "New name: ";
    std::cin >> this->name;
    std::cout << "\nOld weapon type: " << this->weaponType << "\n";
    std::cout << "New weapon type: ";
    std::cin >> this->weaponType;
    std::cout << "\nOld crime type: " << this->crimeType << "\n";
    std::cout << "New crime type: ";
    std::cin >> this->crimeType;
    std::cout << "\nOld habitat: " << this->habitat << "\n";
    std::cout << "New habitat: ";
    std::cin >> this->habitat;
    for (int i = 0; i < this->tempAbility; i++) {
        std::string temp;
        std::cout << "\nOld " << i + 1 << " ability: " << this->abilities[i] << "\n";
        std::cout << "\nNew " << i + 1 << " ability: ";
        std::cin >> temp;
        abilities[i] = temp;
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

void Enemy::saveToFile(std::ofstream &_output) {
    _output << "2\n";
    _output << this->name << "\n";
    _output << this->weaponType << "\n";
    _output << this->crimeType << "\n";
    _output << this->habitat << "\n";
    _output << this->tempAbility << "\n";
    _output << this->abilitySize << "\n";
    for (int i = 0; i < this->tempAbility; i++)
        _output << this->abilities[i] << "\n";
}

void Enemy::getFromFile(std::ifstream &_input) {
    std::string temp;
    int abilityNumber;
    std::getline(_input, temp);
    this->name = temp;
    std::getline(_input, temp);
    this->weaponType = temp;
    std::getline(_input, temp);
    this->crimeType = temp;
    std::getline(_input, temp);
    this->habitat = temp;
    std::getline(_input, temp);
    abilityNumber = std::stoi(temp);
    std::getline(_input, temp);
    this->abilitySize = std::stoi(temp);
    for (int i = 0; i < abilityNumber; i++) {
        std::getline(_input, temp);
        setAbility(temp);
    }
}

void Enemy::setName(std::string _name) {
    this->name = _name;
}

std::string Enemy::getName() {
    return this->name;
}

void Enemy::setWeapon(std::string _weapon) {
    this->weaponType = _weapon;
}

std::string Enemy::getWeapon() {
    return this->weaponType;
}

void Enemy::setCrimeType(std::string _crime) {
    this->crimeType = _crime;
}

std::string Enemy::getCrimeType() {
    return this->crimeType;
}

void Enemy::setHabitat(std::string _habitat) {
    this->habitat = _habitat;
}

std::string Enemy::getHabitat() {
    return this->habitat;
}

void Enemy::setAbility(std::string _ability) {
    if (tempAbility == abilitySize - 1) {
        abilities[tempAbility] = _ability;
        std::string *newAbility = new std::string[abilitySize + 10];
        for (int i = 0; i < tempAbility; i++)
            newAbility[i] = abilities[i];
        delete[] abilities;
        abilities = newAbility;
        abilitySize += 10;
    } else {
        abilities[tempAbility] = _ability;
        tempAbility++;
    }
}

std::string *Enemy::getAbility() {
    return this->abilities;
}

void Enemy::setTempAbility(int _tempAbility) {
    this->tempAbility = _tempAbility;
}

int Enemy::getTempAbility() {
    return this->tempAbility;
}

void Enemy::setAbilitySize(int _abilitySize) {
    this->abilitySize = _abilitySize;
}

int Enemy::getAbilitySize() {
    return this->abilitySize;
}
