#include <iostream>
#include "Simulation.h"

int main() {
    srand(time(NULL));
    // vector<size_t>({airplanes, cars, gates, passengers, guards});
    std::vector<size_t> arg({2,10,6,10,2});
    Simulation s(arg);
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return 0;
}