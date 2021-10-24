#ifndef LAB1_MONSTER_H
#define LAB1_MONSTER_H

#include "Heroes.h"

class Monster : Heroes{
public:
    void setName(std::string name) override;
    std::string getName() override;
private:
    std::string name;
    std::string describe;
};


#endif //LAB1_MONSTER_H
