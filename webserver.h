#ifndef WEBSERVER_H
#define WEBSERVER_H

#include <stdlib.h> // for using sleep()

#include "request.h"

/**
 * weberver object:
 *  Receives requests from loadbalancer
 *  Process requests
 *  Request another     
 */
class webserver
{
    private:
        int serverID;
        bool isBusy;   
    public:
        // constructor
        webserver(int id) : serverID(id), isBusy(false) {};

        // getters
        int get_serverID() const { return serverID; }
        int isAvailable() const { return !isBusy; }

        // method to process request
        void handle_request(const request& request);
};

#endif