#include <iostream>
#include "Simulation.h"

int main() {
    std::vector<size_t> arg({3,2,0,0,0});
    Simulation s(arg);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    s.stopAll();
    while (!s.isAllFinished()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    std::cout << "Zakończono!" << std::endl;
    return 0;
}