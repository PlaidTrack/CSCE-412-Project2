#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"
#include "request_queue.h"

/**
 * Server object:
 *  Receives requests from loadbalancer
 *  Process requests
 *  Request another     
 */
class webserver
{
    public:
        webserver(string name);

        void handle_request(request r, int timestamp);
        
        request current_request;
        int current_wait;
        string server_name;
};

#endif