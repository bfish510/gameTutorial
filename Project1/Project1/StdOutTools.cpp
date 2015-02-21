#include "StdOutTools.h"
#include <iostream>
#include <string>

void StdOutTools::fatalError(std::string errorMessage) {
    std::cout << errorMessage << std::endl;
    StdOutTools::pressAnyKeyToExit();
}

void StdOutTools::pressAnyKeyToExit() {
    std::cout << "Enter any key to quit";
    int tmp;
    std::cin >> tmp;
}