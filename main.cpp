#include <iostream>
#include <string>

#include "request.h"
#include "request_queue.h"
#include "webserver.h"
#include "loadbalancer.h"

int main()
{
    string user_input;
    int num_servers;
    int runtime;
    int initial_requests = 3;

    cout << "Please enter the number of servers: ";
    getline(cin, user_input);
    num_servers = stoi(user_input);

    cout << "Please enter the amount of time you would like to run the load balancer: ";
    getline(cin, user_input);
    runtime = stoi(user_input);

    //start the load balancer
    cout << "Starting load balancer..." << endl;
    loadbalancer load_balancer(runtime, num_servers, initial_requests);
    load_balancer.initialize();
    load_balancer.run();

    //Once the load balancer stops running, it means that time is up or queue is empty
    cout << "Done" << endl;
    for(int i = 0; i < load_balancer.handled_requests.size(); i++)
    {
        cout << "At " << load_balancer.handled_times[i] << " " 
            << load_balancer.handled_webservers[i].server_name << " processed request from " 
            << load_balancer.handled_requests[i].get_IP_in() << " to " << 
            load_balancer.handled_requests[i].get_IP_out() << endl;
    }

    return 0;
}