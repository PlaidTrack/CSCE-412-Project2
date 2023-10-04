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

#include <vector>
#include "request_queue.h"
#include "webserver.h"


class loadbalancer
{
    public:
        // individual server request info
        int runtime;
        int num_servers;
        int initial_requests;
        int clock;

        // requests and webserver objects
        request_queue requests;
        vector<webserver> webservers;
        queue<webserver> free_webservers;
        vector<request> handled_requests;
        vector<webserver> handled_webservers;
        vector<string> handled_times;

        // constructor
        loadbalancer(int rn_t, int num_serv, int init_req);

        vector<webserver> start_webservers();
        request_queue add_requests();   // populate request_queue list
        void initialize();
        void run();
        void assign_requests();
        void server_sweeep();
};

#endif