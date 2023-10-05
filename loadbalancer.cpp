//loadbalancer.cpp

#include "loadbalancer.h"

void loadbalancer::add_request_to_queue(const request& req)
{
    request_queue.push(req);

    cout << "Request from " << req.get_IP_in() << " to " << req.get_IP_out()
         << " added to the queue." << endl;
}

void loadbalancer::route_request_to_server()
{
    if (!request_queue.empty())
    {
        for (webserver& server : webservers)
        {
            if (server.isAvailable())
            {
                request req = request_queue.front();
                request_queue.pop();
                server.handle_request(req);
                return; // exit after routing one request
            }
        }
    } else
    {
        cout << "No requests in the queue." << endl;
    }
}

void loadbalancer::update_server_status()
{
    cout << "Server has been updated" << endl;
}

void loadbalancer::run(int simulation_duration)
{
    while (current_time < simulation_duration)
    {
        // Add random requests to the queue for simulation (1/10 chance)
        if (rand() % 10 == 0)
        {
            request random_request = request::generate_random_request();
            add_request_to_queue(random_request);
        }

    // Route requests to available servers
    route_request_to_server();

    current_time++;

    update_server_status();
    }
}