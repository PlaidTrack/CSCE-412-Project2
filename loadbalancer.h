/*ALEXANDER GONZALES
* LOADBALANCER_H_FILE
* Author    : Alexander Gonzales
---------------------------------------------------*/
/****************************************************/
/*               LOADBALANCER GUARDS                */
/****************************************************/
#ifndef LOADBALANCER_H
#define LOADBALANCER_H

/****************************************************/
/*                   DEPENDANCIES                   */
/****************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
#include <ctime>

#include "request.h"
#include "webserver.h"

class loadbalancer
{
    private:
        queue<request> request_queue;
        vector<webserver> webservers;
        int current_time;

    public:
        // Constructor, seed random number generator
        loadbalancer(const vector<webserver>& servers) : webservers(servers), current_time(0) { srand(static_cast<unsigned int>(std::time(nullptr))); }

        // Add a request to the queue
        void add_request_to_queue(const request& req);

        // Route a request to an available server
        void route_request_to_server();

        // Update the status of web servers (text output)
        void update_server_status();

        // Simulate load balancing
        void run(int simulation_duration);
};

#endif