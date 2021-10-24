#ifndef LAB1_KEEPER_H
#define LAB1_KEEPER_H

#include "Heroes.h"

class Keeper {
public:
    Keeper();
    void addHero(Heroes& currentHero);
    void removeHero(std::string currentName);
    void saveClassInFile(std::string fileName);
    void getClassFromFile(std::string fileName);
private:
    Heroes* heroesKeeper;
};


#endif //LAB1_KEEPER_H
