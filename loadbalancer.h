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
#include <fstream>
#include <limits.h>

#include "request.h"
#include "webserver.h"

class loadbalancer
{
    private:
        queue<request> request_queue;
        vector<webserver> webservers;
        int current_time;
        int starting_queue_size;
        int ending_queue_size;
        int min_task_time;
        int max_task_time;

        ofstream outputFile;

    public:
        // Constructor, seed random number generator
        loadbalancer(const vector<webserver>& servers) : webservers(servers), current_time(0), 
        starting_queue_size(0), ending_queue_size(0), min_task_time(INT_MAX), max_task_time(0)
        { 
            srand(static_cast<unsigned int>(std::time(nullptr)));

            // Open the output file for writing
            outputFile.open("Loadbalancing_Log.txt");    
        }
        
        // Destructor for output file
        ~loadbalancer()
        {
            // Close output file when loadbalancer object is destroyed
            outputFile.close();
        }

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