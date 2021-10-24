#ifndef LAB1_MONSTER_H
#define LAB1_MONSTER_H

#include <iostream>
#include "Heroes.h"

class Monster : public Heroes{
public:
    void setName(std::string _name) override;
    std::string getName() override;
    void printInfo() override;
    void setDescribe(std::string _describe);
    std::string getDescribe();

private:
    std::string name;
    std::string describe;
};


#endif //LAB1_MONSTER_H
