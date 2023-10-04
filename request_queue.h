#ifndef REQUEST_QUEUE_H
#define REQUEST_QUEUE_H

#include <queue>

#include "request.h"

class request_queue
{
    public:
        request_queue();

        queue<request> get_requests() { return requests; }

        void add_request(request req);
        request pop_request();
        bool is_empty();

        // request queue object
        queue<request> requests;
};

#endif