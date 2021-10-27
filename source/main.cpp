#include <iostream>

#include "Heroes.h"
#include "Keeper.h"

void printFirstInformation(){
    std::cout << "\nMake your choice:\n";
    std::cout << "1. Add Hero\n";
    std::cout << "2. Remove Hero\n";
    std::cout << "3. Change one of heroes\n";
    std::cout << "4. Save your pack of Heroes in file\n";
    std::cout << "5. Get your pack of Heroes from file\n";
    std::cout << "6. Print info about heroes\n";
    std::cout << "7. Exit\n";
}

int main(){
    Keeper keeper;
    int choicer;
    std::cout << "Hello!\n\n";
    while (true){
        printFirstInformation();
        std::cout << "Write a number: ";
        std::cin >> choicer;
        std::cout << "\n";
        if(choicer == 7) {
            std::cout << "Bye\n";
            break;
        }
        try{
            keeper.firstDataProcessing(choicer);
        }
        catch (const char* error){
            std::cerr << error;
        }
        }
    return 0;
}