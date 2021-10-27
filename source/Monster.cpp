#include "Monster.h"

Monster::Monster(){
    std::cout << "Object Monster. Call simple constructor\n";
}

Monster::Monster(std::string _name, std::string _describe) : name(_name), describe(_describe) {
    std::cout << "Object Monster. Call constructor with parameters\n";
}

Monster::Monster(const Monster &monster) : name(monster.name), describe(monster.describe) {
    std::cout << "Object Monster. Call copy constructor\n";
}

Monster::~Monster(){
    std::cout << "Object Monster. Call destructor\n";
}

void Monster::printInfo() {
    std::cout << "Monster name: " << this->name << "\n";
    std::cout << "Monster describe: " << this->describe << "\n\n";
}

void Monster::changeInfo() {
    std::cout << "Old name: " << this->name << "\n";
    std::cout << "New name: ";
    std::cin >> this->name;
    std::cout << "\nOld describe: " << this->describe << "\n";
    std::cout << "New describe: ";
    std::cin >> this->describe;
}

void Monster::saveToFile(std::ofstream& _output) {
    _output << "3\n";
    _output << this->name << "\n";
    _output << this->describe << "\n";
}

void Monster::getFromFile(std::ifstream& _input) {
    std::string temp;
    std::getline(_input, this->name);
    std::getline(_input, this->describe);
}

void Monster::setName(std::string _name) {
    this->name = _name;
}

std::string Monster::getName() {
    return this->name;
}

void Monster::setDescribe(std::string _describe) {
    this->describe = _describe;
}

std::string Monster::getDescribe() {
    return this->describe;
}