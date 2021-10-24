#include <iostream>

#include "Heroes.h"
#include "Keeper.h"

void printFirstInformation(){
    std::cout << "Make your choice:\n";
    std::cout << "1. Add Hero\n";
    std::cout << "2. Remove Hero\n";
    std::cout << "3. Save your pack of Heroes in file\n";
    std::cout << "4. Get your pack of Heroes from file\n";
    std::cout << "5. Exit\n";
}

int main(){
    Keeper keeper;
    int choicer;
    std::cout << "Hello!\n\n";
    while (true){
        printFirstInformation();
        std::cout << "Write a number: ";
        std::cin >> choicer;
        if(choicer == 5) {
            std::cout << "Bye\n";
            break;
        }
    }
    return 0;
}