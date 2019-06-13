//
// Created by darek on 10.06.19.
//

#include "Resource.h"

Resource::Resource() : rstatus(FREE), owner_id(-1) {

}

Resource::~Resource() {

}

void Resource::request(int requester_id) {
    while(owner_id != requester_id) {
        if(rstatus == RStatus::FREE) {
            //std::lock_guard<std::mutex> lock(mutex);
            mutex.lock();
            rstatus = RStatus::IN_USE;
            owner_id = requester_id;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 50 + 1));
        }
    }
}

void Resource::free() {
    rstatus = RStatus::FREE;
    mutex.unlock();
}