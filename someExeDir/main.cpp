#include <iostream>
#include "someLib.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << someLib::getMessage() << std::endl;
    return 0;
}
