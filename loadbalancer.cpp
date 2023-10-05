//loadbalancer.cpp

#include "loadbalancer.h"

void loadbalancer::add_request_to_queue(const request& req)
{
    request_queue.push(req);
    ending_queue_size = request_queue.size();

    // Add data to output file
    outputFile << "Time: " << current_time << ", Starting Queue Size: " << starting_queue_size
               << ", Ending Queue Size: " << ending_queue_size
               << ", Min Task Time: " << min_task_time << ", Max Task Time: " << max_task_time << "\n";

    starting_queue_size = ending_queue_size;

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
                
                // Update m
                if (req.get_process_time() < min_task_time) {
                    min_task_time = req.get_process_time();
                }
                if (req.get_process_time() > max_task_time) {
                    max_task_time = req.get_process_time();
                }
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
    starting_queue_size = 0; // initialize starting queue size

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

        outputFile << "Time: " << current_time << ", Starting Queue Size: " << starting_queue_size
                << ", Ending Queue Size: " << ending_queue_size
                << ", Min Task Time: " << min_task_time << ", Max Task Time: " << max_task_time << "\n";

        starting_queue_size = ending_queue_size;
    }
}