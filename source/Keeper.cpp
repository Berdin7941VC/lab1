#include "Keeper.h"

Keeper::Keeper() {
    std::cout << "Object Keeper. Call a simple constructor\n";
    this->heroesKeeper = new Heroes*[10];
    this->arraySize = 10;
}

Keeper::~Keeper() {
    std::cout << "Object Keeper. Call destructor\n";
    for(int i=0;i<this->tempKeep;i++)
        delete this->heroesKeeper[i];
    delete [] this->heroesKeeper;
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
            std::string heroName;
            std::string heroWeaponType;

            std::cout << "\nWrite hero name: ";
            std::cin >> heroName;
            std::cout << "Write hero weapon type: ";
            std::cin >> heroWeaponType;

            Hero* newHero = new Hero(heroName, heroWeaponType);

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

            this->addHeroToArray(newHero);
            break;
        }

        case 2: {
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

            Enemy* newEnemy = new Enemy(enemyName, enemyWeaponType, enemyCrime, enemyHabitat);

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

            this->addHeroToArray(newEnemy);
            break;
        }
        case 3:{
            std::string monsterName;
            std::string monsterDescribe;
            std::cout << "\nWrite monster name: ";
            std::cin >> monsterName;
            std::cout << "Describe monster(one word): ";
            std::cin >> monsterDescribe;

            Monster *newMonster = new Monster(monsterName, monsterDescribe);

            this->addHeroToArray(newMonster);
            break;
        }
        default:
            std::cerr << "Error: Unknown type of Heroes!\n";
    }
}

void Keeper::removeHero() {
    int number;
    std::cout << "Enter number of Hero what you want to delete: ";
    std::cin >> number;
    if(number > this->tempKeep || number < 1)
        std::cerr << "Error: Wrong hero number\n";
    delete this->heroesKeeper[number-1];
    for(int i = number-1;i<this->tempKeep;i++)
        this->heroesKeeper[i] = this->heroesKeeper[i+1];
    this->tempKeep--;
}

void Keeper::changeInfo() {
    int tempHero;
    std::cout << "Print a number of Heroes: ";
    std::cin >> tempHero;
    std::cout << "\n";
    if(tempHero > this->tempKeep || tempHero < 0)
        std::cerr << "Error: Hero with this number is doesn't exists\n";
    this->heroesKeeper[tempHero-1]->changeInfo();
}

void Keeper::saveClassInFile() {
    std::ofstream output;
    output.open("save");
    output << this->tempKeep << "\n";
    output << this->arraySize << "\n";
    for(int i=0;i < tempKeep;i++)
        this->heroesKeeper[i]->saveToFile(output);
    output.close();
}

void Keeper::getClassFromFile() {
    clearHeroes();
    std::ifstream input;
    int heroesNumber;
    input.open("save");
    if(!input.is_open())
        throw std::invalid_argument("File is not exists!\n");
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
                default:
                    throw std::invalid_argument("Unknown type of Heroes in save file!\n");
            }
        }
        else
            throw std::out_of_range("Unexpected EOF\n");
    }
    input.close();
}

void Keeper::printInfo() {
    if(this->tempKeep == 0){
        std::cerr << "Error: You have not heroes\n";
        return;
    }
    for(int i=0;i<this->tempKeep;i++) {
        std::cout << i + 1 << ".\n";
        this->heroesKeeper[i]->printInfo();
    }
}

void Keeper::addHeroToArray(Heroes* heroes) {
    if(this->tempKeep == this->arraySize-1){
        this->heroesKeeper[this->tempKeep] = heroes;
        Heroes** newArray = new Heroes*[this->arraySize+10];
        for(int i=0;i<this->arraySize;i++)
            newArray[i] = this->heroesKeeper[i];
        delete[] this->heroesKeeper;
        this->heroesKeeper = newArray;
        this->arraySize += 10;
        this->tempKeep++;
    }
    else {
        this->heroesKeeper[this->tempKeep] = heroes;
        this->tempKeep++;
    }
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
            this->changeInfo();
            break;
        case 4:
            this->saveClassInFile();
            break;
        case 5:
            this->getClassFromFile();
            break;
        case 6:
            this->printInfo();
            break;
        default:
            std::cerr << "Error: Wrong number. Number should be from 1 to 7!";
    }
}

void Keeper::clearHeroes() {
    for(int i=0;i<this->tempKeep;i++)
        delete this->heroesKeeper[i];
}