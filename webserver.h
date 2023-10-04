#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "request.h"
#include "request_queue.h"

class webserver
{
    public:
        webserver(string name);

        void handle_request(request r, int timestamp);

    private:
        request current_request;
        int current_wait;
        string server_name;
};

#endif