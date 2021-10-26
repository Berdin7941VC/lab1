#ifndef LAB1_MONSTER_H
#define LAB1_MONSTER_H

#include <iostream>
#include <fstream>

#include "Heroes.h"

struct MonsterData{
    int type;
    std::string _name;
    std::string _describe;
};

class Monster : public Heroes{
public:
    void setName(std::string _name) override;
    std::string getName() override;
    void printInfo() override;
    void saveToFile(std::ofstream& _output) override;
    void getFromFile(std::ifstream& _input) override;
    void setDescribe(std::string _describe);
    std::string getDescribe();
private:
    std::string name;
    std::string describe;
};


#endif //LAB1_MONSTER_H
