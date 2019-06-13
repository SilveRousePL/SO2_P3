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

    mvprintw(0, 5, "Threads");
    mvprintw(0, 27, "Progress");
    mvprintw(0, 62, "Status");

    for(uint i = 0; i < 84; i++) {
        mvprintw(1, i, "-");
        mvprintw(objects->sizeThr() + 2, i, "-");
    }

    for(uint i = 0; i < objects->sizeThr() + 3; i++) {
        mvprintw(i, 0, "|");
        mvprintw(i, 16, "|");
        mvprintw(i, 45, "|");
        mvprintw(i, 83, "|");
    }
}

Visualisation::~Visualisation() {
    endwin();
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

            if(row.find("Airplane") == 0) {
                attron(COLOR_PAIR(7));
            } else if(row.find("Car") == 0) {
                attron(COLOR_PAIR(4));
            } else if(row.find("Passenger") == 0) {
                attron(COLOR_PAIR(3));
            } else if(row.find("Guard") == 0) {
                attron(COLOR_PAIR(8));
            }

            if(row.find("queue") != std::string::npos) {
                attron(COLOR_PAIR(5));
            }

            if(row.find("!") != std::string::npos) {
                attron(COLOR_PAIR(1));
            }

            if(row.find("Finished") != std::string::npos) {
                attron(COLOR_PAIR(2));
            }

            mvprintw(y, x, row.c_str());

            attroff(COLOR_PAIR(1));
            attroff(COLOR_PAIR(2));
            attroff(COLOR_PAIR(3));
            attroff(COLOR_PAIR(4));
            attroff(COLOR_PAIR(5));
            attroff(COLOR_PAIR(6));
            attroff(COLOR_PAIR(7));
            attroff(COLOR_PAIR(8));
        }

        std::string free_gates = "Free gates: " + std::to_string(objects->freeGates());
        std::string all_gates = "All gates:  " + std::to_string(objects->gate.size());
        mvprintw(objects->sizeThr() + 4, 1, free_gates.c_str());
        mvprintw(objects->sizeThr() + 5, 1, all_gates.c_str());
        mvprintw(objects->sizeThr() + 7, 1, information.c_str());
        mvprintw(objects->sizeThr() + 8, 0, " ");

        refresh();
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}