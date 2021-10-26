#include "Monster.h"

void Monster::setName(std::string _name) {
    this->name = _name;
}

std::string Monster::getName() {
    return this->name;
}

void Monster::printInfo() {
    std::cout << "Monster name: " << this->name << "\n";
    std::cout << "Monster describe: " << this->describe << "\n\n";
}

void Monster::setDescribe(std::string _describe) {
    this->describe = _describe;
}

std::string Monster::getDescribe() {
    return this->describe;
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