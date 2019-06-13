//
// Created by darek on 10.06.19.
//

#ifndef SO2_P3_RESOURCE_H
#define SO2_P3_RESOURCE_H
#include <mutex>
#include <thread>

class Resource {
public:
    enum Status {
        FREE,
        IN_USE,
    } status;

    int owner_id;
    std::mutex mutex;

    Resource();
    Resource(const Resource&) = delete;
    virtual ~Resource();

    void request(int requester_id);
    void free();
};


#endif //SO2_P3_RESOURCE_H
