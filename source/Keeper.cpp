#include "Keeper.h"

Keeper::Keeper() {
    std::cout << "Call a simple constructor\n";
    heroesKeeper = new Heroes*[10];
    arraySize = 10;
    saveArray = new int[10];
}

void Keeper::addHero() {
    int chooser;
    std::cout << "\nChoose hero type:\n";
    std::cout << "1. Hero\n";
    std::cout << "2. Enemy\n";
    std::cout << "3. Monster\n";
    std::cout << "Write a number: ";
    std::cin >> chooser;
    switch (chooser) {
        case 1 : {
            Hero *newHero = new Hero();
            std::string heroName;
            std::string heroWeaponType;
            std::cout << "\nWrite hero name: ";
            std::cin >> heroName;
            std::cout << "Write hero weapon type: ";
            std::cin >> heroWeaponType;
            newHero->setName(heroName);
            newHero->setWeapon(heroWeaponType);
            while (true) {
                std::string ability;
                int yesNo;
                std::cout << "Enter ability: ";
                std::cin >> ability;
                newHero->setAbility(ability);
                std::cout << "Want add another ability?\n1 - Yes, 2 - No\nEnter a number: ";
                std::cin >> yesNo;
                if (yesNo == 1)
                    continue;
                else
                    break;
            }
            saveArray[tempKeep] = 1;
            this->addHeroToArray(newHero);
            break;
        }

        case 2: {
            Enemy *newEnemy = new Enemy();
            std::string enemyName;
            std::string enemyWeaponType;
            std::string enemyCrime;
            std::string enemyHabitat;
            std::cout << "\nWrite enemy name: ";
            std::cin >> enemyName;
            std::cout << "Write enemy weapon type: ";
            std::cin >> enemyWeaponType;
            std::cout << "Write enemy crime: ";
            std::cin >> enemyCrime;
            std::cout << "Write enemy habitat: ";
            std::cin >> enemyHabitat;
            newEnemy->setName(enemyName);
            newEnemy->setWeapon(enemyWeaponType);
            newEnemy->setCrimeType(enemyCrime);
            newEnemy->setHabitat(enemyHabitat);
            while (true) {
                std::string ability;
                int yesNo;
                std::cout << "Enter ability: ";
                std::cin >> ability;
                newEnemy->setAbility(ability);
                std::cout << "Want add another ability?\n1 - Yes, 2 - No\nEnter a number: ";
                std::cin >> yesNo;
                if (yesNo == 1)
                    continue;
                else
                    break;
            }
            saveArray[tempKeep] = 2;
            this->addHeroToArray(newEnemy);
            break;
        }
        case 3:{
            Monster *newMonster = new Monster();
            std::string monsterName;
            std::string monsterDescribe;
            std::cout << "\nWrite monster name: ";
            std::cin >> monsterName;
            std::cout << "Describe monster: ";
            std::cin >> monsterDescribe;
            newMonster->setName(monsterName);
            newMonster->setDescribe(monsterDescribe);
            saveArray[tempKeep] = 3;
            this->addHeroToArray(newMonster);
            break;
        }
    }
}

void Keeper::removeHero() {
    int number;
    std::cout << "Enter number of Hero what you want to delete: ";
    std::cin >> number;
    if(number > tempKeep || number < 1) {
        std::cout << "Wrong hero number\n";
        return;
    }
    delete heroesKeeper[number-1];
    for(int i = number-1;i<tempKeep;i++)
        heroesKeeper[i] = heroesKeeper[i+1];
    tempKeep--;
}

void Keeper::saveClassInFile() {
    std::ofstream output;
    output.open("save");
    output << this->tempKeep << "\n";
    output << this->arraySize << "\n";
    for(int i=0;i < tempKeep;i++)
        heroesKeeper[i]->saveToFile(output);
    output.close();
}

void Keeper::getClassFromFile() {
    clearHeroes();
    std::ifstream input;
    int heroesNumber;
    input.open("save");
    std::string temp;
    std::getline(input, temp);
    heroesNumber = std::stoi(temp);
    std::getline(input, temp);
    this->arraySize = std::stoi(temp);
    for(int i=0;i<heroesNumber;i++) {
        std::getline(input, temp);
        if (!input.eof()) {
            int tempCase = std::stoi(temp);
            switch (tempCase) {
                case 1: {
                    Hero *hero = new Hero();
                    hero->getFromFile(input);
                    this->addHeroToArray(hero);
                    break;
                }
                case 2: {
                    Enemy *enemy = new Enemy();
                    enemy->getFromFile(input);
                    this->addHeroToArray(enemy);
                    break;
                }
                case 3: {
                    Monster *monster = new Monster();
                    monster->getFromFile(input);
                    this->addHeroToArray(monster);
                    break;
                }
            }
        }
        else
            break;
    }
    input.close();
}

void Keeper::firstDataProcessing(int chooseMode) {
    switch (chooseMode) {
        case 1:
            this->addHero();
            break;
        case 2:
            this->removeHero();
            break;
        case 3:
            this->saveClassInFile();
            break;
        case 4:
            this->getClassFromFile();
            break;
        case 5:
            this->printInfo();
            break;
        default:
            std::cout << "Wrong choose-number";
            break;
    }
}

void Keeper::addHeroToArray(Heroes* heroes) {
    if(tempKeep == arraySize-1){
        heroesKeeper[tempKeep] = heroes;
        Heroes** newArray = new Heroes*[arraySize+10];
        for(int i=0;i<arraySize;i++)
            newArray[i] = heroesKeeper[i];
        delete[] heroesKeeper;
        heroesKeeper = newArray;
        arraySize += 10;
        int* newSaveArray = new int[arraySize];
        for(int i=0;i<tempKeep;i++)
            newSaveArray[i] = saveArray[i];
        delete[] saveArray;
        saveArray = newSaveArray;
        tempKeep++;
    }
    else {
        heroesKeeper[tempKeep] = heroes;
        tempKeep++;
    }
}

void Keeper::printInfo() {
    if(tempKeep == 0){
        std::cout << "You have not heroes\n";
        return;
    }
    for(int i=0;i<tempKeep;i++) {
        std::cout << i + 1 << ".\n";
        heroesKeeper[i]->printInfo();
    }
}

void Keeper::clearHeroes() {
    for(int i=0;i<tempKeep;i++)
        delete heroesKeeper[i];
}