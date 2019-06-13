#ifndef SO2_P3_VISUALISATION_H
#define SO2_P3_VISUALISATION_H

#include <ncurses.h>
#include <vector>
#include "Objects.h"

class Visualisation {
public:
    std::vector<std::string> id;
    //std::vector<std::string> threadStatus;
    std::vector<std::string> resourcesStatus;
    //std::vector<std::string> progress;
    std::vector<bool> finished;

    std::vector<std::string> row_object;
    Objects* objects;

    std::string information;


    Visualisation(Objects* objects);
    ~Visualisation();

    void start();

    void initTableInfo(std::vector<std::string> id, std::vector<std::string> resourcesStatus, std::vector<bool> isFinished);
    void updateTableInfo(int global_id, std::string row_object, bool isFinished);
    //void updateProgress(uint id, std::string progress);
    void updateResources(int global_id, std::string resourcesStatus);
};

#endif //SO2_P3_VISUALISATION_H