#ifndef LAB1_HERO_H
#define LAB1_HERO_H

#include "Heroes.h"

class Hero : Heroes{
public:
    std::string getName() override;
    void setName(std::string name) override;
private:
    std::string name;
    std::string weaponType;
};


#endif //LAB1_HERO_H
