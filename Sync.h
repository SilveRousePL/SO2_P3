//
// Created by darek on 30.05.19.
//

#ifndef SO2_P3_SYNC_H
#define SO2_P3_SYNC_H

#include <mutex>
#include <condition_variable>

class Sync {
    std::mutex mutex;
    std::condition_variable cv;

public:
    void wait() {
        std::unique_lock <std::mutex> lock(mutex);
        cv.wait(lock);
    }

    void notifyAll() {
        std::unique_lock <std::mutex> lock(mutex);
        cv.notify_all();
    }
};

#endif //SO2_P3_SYNC_H
