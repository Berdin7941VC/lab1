#ifndef LAB1_HEROES_H
#define LAB1_HEROES_H
#include <string>

class Heroes {
public:
    virtual void setName(std::string name) = 0;
    virtual std::string getName() = 0;
    virtual void printInfo() = 0;
    virtual void saveToFile(std::ofstream& _output) = 0;
    virtual void getFromFile(std::ifstream& _input) = 0;

private:
    std::string name;
};


#endif //LAB1_HEROES_H
