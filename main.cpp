#include <iostream>
#include <string>
#include <vector>

#include "request.h"
#include "webserver.h"
#include "loadbalancer.h"

int main()
{
    string user_input;
    
    // loadbalancer parameters
    vector<webserver> webservers;
    int num_servers;
    int runtime;

    cout << "Number of servers: ";
    getline(cin, user_input);
    num_servers = stoi(user_input);

    for (int i = 0; i < num_servers; i++)
    {
        webserver server(i);
        webservers.push_back(server);
    }

    // create load balancer with the vector of web servers
    loadbalancer load_balancer(webservers);

    cout << "Number of clock cycles you would like to run the load balancer: ";
    getline(cin, user_input);
    runtime = stoi(user_input);

    load_balancer.run(runtime);

    return 0;
}