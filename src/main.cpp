#include <iostream>
#include <stdexcept>
#include "window.h"

int main() {
    try {
        Window window;
        window.mainLoop();
    }
    catch (const std::exception& error) {
        std::cerr << "std::exception: " << error.what() << std::endl;
        return -1;
    }
    catch (...) {
        std::cerr << "unknown error" << std::endl;
        return -1;
    }

    return 0;
}
