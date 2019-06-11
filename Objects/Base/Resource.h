//
// Created by darek on 10.06.19.
//

#ifndef SO2_P3_RESOURCE_H
#define SO2_P3_RESOURCE_H
#include <mutex>

class Resource {
public:
    std::mutex mutex;

    Resource();
    Resource(const Resource&) = delete;
    virtual ~Resource();
};


#endif //SO2_P3_RESOURCE_H
