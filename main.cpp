#include <iostream>
#include "Simulation.h"

int main() {
    srand(time(NULL));
    // vector<size_t>({airplanes, cars, gates, guards, passengers});
    std::vector<size_t> arg({2,10,6,2,10});
    Simulation s(arg);
    std::this_thread::sleep_for(std::chrono::seconds(5));
    s.stopAll();
    while (!s.isAllFinished()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    std::cout << "Zakończono!" << std::endl;
    return 0;
}