
#ifndef LAB1_ENEMY_H
#define LAB1_ENEMY_H

#include "Heroes.h"

class Enemy : Heroes{
public:
    void setName(std::string name) override;
    std::string getName() override;

private:
    std::string name;
    std::string weaponType;
    std::string crimeType;
    std::string habitat;
    std::string ability;
};


#endif //LAB1_ENEMY_H
