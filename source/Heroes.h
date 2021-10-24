#ifndef LAB1_HEROES_H
#define LAB1_HEROES_H
#include <string>

class Heroes {
    virtual void setName(std::string name) = 0;
    virtual std::string getName() = 0;
};


#endif //LAB1_HEROES_H
