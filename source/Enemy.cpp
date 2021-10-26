#include "Enemy.h"

Enemy::Enemy() {
    abilities = new std::string[10];
    abilitySize = 10;
}
void Enemy::setName(std::string _name) {
    this->name = _name;
}

std::string Enemy::getName() {
    return name;
}

void Enemy::printInfo() {
    std::cout << "Enemy name: " << this->name << "\n";
    std::cout << "Enemy weapon type: " << this->weaponType << "\n";
    std::cout << "Enemy crime: " << this->crimeType << "\n";
    std::cout << "Enemy habitat: " << this->habitat << "\n";
    if(tempAbility == 1)
        std::cout << "Enemy ability: " << this->abilities[0] << "\n\n";
    else {
        std::cout << "Enemy abilities: " << this->abilities[0] << ", ";
        for (int i = 1; i < tempAbility - 1; i++)
            std::cout << abilities[i] << ", ";
        std::cout << abilities[tempAbility - 1] << "\n\n";
    }
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

std::string* Enemy::getAbility() {
    return abilities;
}

void Enemy::saveToFile(std::ofstream& _output) {
    _output << "2\n";
    _output << this->name << "\n";
    _output << this->weaponType << "\n";
    _output << this->crimeType << "\n";
    _output << this->habitat << "\n";
    _output << this->tempAbility << "\n";
    _output << this->abilitySize << "\n";
    for(int i=0;i<this->tempAbility;i++)
        _output << this->abilities[i] << "\n";
}

void Enemy::getFromFile(std::ifstream& _input) {
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
    for(int i=0;i<abilityNumber;i++){
        std::getline(_input, temp);
        setAbility(temp);
    }
}