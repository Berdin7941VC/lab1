#ifndef LAB1_KEEPER_H
#define LAB1_KEEPER_H

#include <iostream>
#include <exception>

#include "Heroes.h"
#include "Hero.h"
#include "Enemy.h"
#include "Monster.h"

struct Data{
};

class Keeper {
public:
    Keeper();
    void addHero();
    void removeHero();
    void saveClassInFile();
    void getClassFromFile();
    void firstDataProcessing(int chooseMode);
    void addHeroToArray(Heroes* heroes);
    void printInfo();
    void clearHeroes();

private:
    Heroes** heroesKeeper;
    int tempKeep = 0;
    int arraySize = 0;
    int* saveArray;
};


#endif //LAB1_KEEPER_H
