#ifndef LAB1_KEEPER_H
#define LAB1_KEEPER_H

#include <iostream>
#include <exception>
#include <string>

#include "Heroes.h"
#include "Hero.h"
#include "Enemy.h"
#include "Monster.h"

class Keeper {
public:
    Keeper();
    ~Keeper();
    void addHero();
    void removeHero();
    void changeInfo();
    void saveClassInFile();
    void getClassFromFile();
    void printInfo();
    void addHeroToArray(Heroes* heroes);
    void firstDataProcessing(int chooseMode);
    void clearHeroes();

private:
    Heroes** heroesKeeper;
    int tempKeep = 0;
    int arraySize = 0;
};


#endif //LAB1_KEEPER_H
