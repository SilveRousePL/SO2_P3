#include "Visualisation.h"

Visualisation::Visualisation(Objects* objects) :
    objects(objects) {
    information = "Press SPACE to end                   ";

    initscr();
    attron(A_BOLD);
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);

    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);

    mvprintw(0, 5, "THREADS");
    mvprintw(0, 27, "PROGRESS");
    mvprintw(0, 57, "STATUS");
    mvprintw(0, 100, "RESOURCES");

    for(uint i = 0; i < 135; i++) {
        mvprintw(1, i, "-");
        mvprintw(objects->sizeThr() + 2, i, "-");
    }

    for(uint i = 0; i < objects->sizeThr() + 3; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, 16, "|");
        mvprintw(i, 135, "|");
        mvprintw(i, 45, "|");
        mvprintw(i, 76, "|");
    }
}

Visualisation::~Visualisation() {
    endwin();
}

//void Visualisation::initTableInfo(std::vector<std::string> id, std::vector<std::string> resourcesStatus, std::vector<bool> isFinished) {
void Visualisation::initTableInfo(std::vector<std::string> id, std::vector<std::string> resourcesStatus, std::vector<bool> isFinished) {
    this->id = id;
    //this->threadStatus = threadStatus;
    this->resourcesStatus = resourcesStatus;
    //this->progress = progress;
    this->finished = isFinished;

    initscr();
    attron(A_BOLD);
    start_color();
    cbreak();
    noecho();
    keypad(stdscr, true);

    init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_BLACK, COLOR_BLACK);

    mvprintw(0, 5, "THREADS");
    mvprintw(0, 27, "ACTIONS");
    mvprintw(0, 57, "PROGRESS");
    mvprintw(0, 100, "RESOURCES");

    for(uint i = 0; i < 135; i++) {
        mvprintw(1, i, "-");
        mvprintw(objects->sizeThr() + 2, i, "-");
    }

    for(uint i = 0; i < objects->sizeThr() + 3; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, 16, "|");
        mvprintw(i, 135, "|");
        mvprintw(i, 45, "|");
        mvprintw(i, 76, "|");
    }
}

void Visualisation::start() {
    bool curFinished = false;
    while (!curFinished) {
        timeout(0);
        int option = getch();
        if (option == ' ') {
            objects->stopAll();
            information = "Finishing...                         ";
        }
        if (objects->stop_operation) {
            bool allFinished = true;

            if (objects->isAllFinished()) {
                curFinished = true;
                information = "Finished!                            ";
            }
        }

        // Draw loop
        for (int i = 0; i < objects->sizeThr(); ++i) {
            uint x = 2;
            uint y = i + 2;
            std::string row;

            row = objects->print(i);

            if(row.find("Airplane") != std::string::npos) {
                attron(COLOR_PAIR(7));
            } else if(row.find("Car") != std::string::npos) {
                attron(COLOR_PAIR(5));
            } else if(row.find("Passenger") != std::string::npos) {
                attron(COLOR_PAIR(3));
            } else if(row.find("Guard") != std::string::npos) {
                attron(COLOR_PAIR(8));
            } else if(row.find("AAA") != std::string::npos) {
                attron(COLOR_PAIR(7));
            } else if(row.find("AAA") != std::string::npos) {
                attron(COLOR_PAIR(8));
            }

            mvprintw(y, x, row.c_str());
            //x = row.length();

            /*if(progress[i].find("+") != std::string::npos) {
                attron(COLOR_PAIR(1));
            } else if(progress[i].find("Z") != std::string::npos) {
                attron(COLOR_PAIR(4));
            } else {
                attron(COLOR_PAIR(4));
            }*/

            //row = threadStatus[i] + "\t" + progress[i] + "\t";

            //mvprintw(y, x, row.c_str());
            //x = x + row.length() + 10;

            /*if(resourcesStatus[i].find("NATURE") != std::string::npos) {
                attron(COLOR_PAIR(2));
            } else if(resourcesStatus[i].find("FARMER") != std::string::npos) {
                attron(COLOR_PAIR(3));  
            } else if(resourcesStatus[i].find("BLACKSMITH") != std::string::npos) {
                attron(COLOR_PAIR(8));
            } else if(resourcesStatus[i].find("NOBODY") != std::string::npos) {
                attron(COLOR_PAIR(6));
            } else if(resourcesStatus[i].find("BAKER") != std::string::npos) {
                attron(COLOR_PAIR(5));
            } else if(resourcesStatus[i].find("CUSTOMER") != std::string::npos) {
                attron(COLOR_PAIR(7));
            } else if(resourcesStatus[i].find("FISHERMAN") != std::string::npos) {
                attron(COLOR_PAIR(8));
            }*/

            //row = resourcesStatus[i] + "\n";
            //mvprintw(y, x, row.c_str());

            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(6));
            attroff(COLOR_PAIR(8));
            attroff(COLOR_PAIR(5));
            attroff(COLOR_PAIR(7));
        }

        mvprintw(objects->sizeThr() + 5, 1, information.c_str());
        mvprintw(objects->sizeThr() + 6, 0, " ");
        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));

        if (curFinished) {
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
    }
}

void Visualisation::updateTableInfo(int global_id, std::string row_object, bool isFinished) {
    this->id[global_id] = row_object;
    this->finished[global_id] = isFinished;
}

void Visualisation::updateResources(int global_id, std::string resourcesStatus) {
    this->resourcesStatus[global_id] = resourcesStatus;
}