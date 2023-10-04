//loadbalancer.cpp
#include <ostream>
#include <iostream>
#include <ctime>

#include "loadbalancer.h"

// constructor
loadbalancer::loadbalancer(int rn_t, int num_serv, int init_req)
{
    runtime = rn_t;
    num_servers = num_serv;
    initial_requests = init_req;
}

vector<webserver> loadbalancer::start_webservers()
{
    vector<webserver> webserver_list;

    cout << "Webservers created: ";

    for (int i = 0; i < num_servers; i++)
    {
        webserver new_webserver("S" + to_string(i));
        cout << "S" << to_string(i);    // print server number
        
        // prevents lingering comma
        if (i != num_servers - 1)
            cout << ", ";
    
        webserver_list.push_back(new_webserver);
        free_webservers.push(new_webserver);
    }

    cout << endl;
    return webserver_list;
}

request_queue loadbalancer::add_requests()
{
    request_queue req;

    for (int i = 0; i < initial_requests; i++)
    {
        request new_request;    // new request
        cout << "New request from " << new_request.get_IP_in() << " to " << new_request.get_IP_out() << " over time " << new_request.get_process_time() << endl;
        req.add_request(new_request);
    }

    cout << "Request queue has been populated with " << to_string(initial_requests) << " requests" << endl;
    return req;
}

void loadbalancer::assign_requests()
{
    webserver current_webserver = free_webservers.front();
    free_webservers.pop();

    request current_request = requests.pop_request();

    int current_timestamp = clock;
    current_webserver.handle_request(current_request, current_timestamp);
}

void loadbalancer::server_sweeep()
{
    int request_time;   // request time
    int request_dur;    // request duration

    for(int i = 0; i < num_servers; i++)
    {
        webserver current_server = webservers[i];

        request_time = current_server.current_request.get_process_time();
        request_dur = clock - current_server.current_wait;

        // webserver is done with request
        if(request_dur >= request_time)
        {
            handled_requests.push_back(current_server.current_request);

            string handled_time = to_string(request_dur);
            handled_times.push_back(handled_time);

            free_webservers.push(current_server);
        }
    }
}

void loadbalancer::initialize()
{
    webservers = start_webservers();    // start up webservers
    requests = add_requests();          // fill up request queue
}

void loadbalancer::run()
{
    clock = 0;  // reset clock

    // check if requests are empty
    while (clock < runtime && !requests.is_empty())
    {
        clock += 1;

        if(!requests.is_empty() && free_webservers.empty())
            server_sweeep();
        
        while(!free_webservers.empty() && !requests.is_empty())
            assign_requests();
    }
}