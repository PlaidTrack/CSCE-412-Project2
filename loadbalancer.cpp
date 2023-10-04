//loadbalancer.cpp

#ifndef LOADBALANCER_H
#include "loadbalancer.h"
#endif

int loadbalancer::get_time()
{
    return system_time;
}

void loadbalancer::inc_time()
{
    system_time++;
}

void loadbalancer::add_request(request r)
{
    request_queue.push(r);
    inc_time();
}

request loadbalancer::get_request()
{
    inc_time();
    if (!request_queue.empty())
    {
        request r = request_queue.back();
        return r;
    }
}

bool loadbalancer::is_request_queue_empty()
{
    return request_queue.empty();
}