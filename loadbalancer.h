//loadbalancer.h
#ifndef REQUEST_CPP
#define LOADBALANCER_H

#include <queue>
#include "request.cpp"
#endif

class loadbalancer
{
    public:
        loadbalancer()
        {
            system_time = 0;
        }
        int get_time();
        void inc_time();                // makes sure time is incremented
        void add_request(request r);    // adds request to queue
        request get_request();          // get a request out of queue
        bool is_request_queue_empty();  // ask loadbalancer if queue is empty
    private:
        int system_time;
        queue <request> request_queue;  //
};