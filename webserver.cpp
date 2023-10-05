//webserver.cpp

#include "webserver.h"

void webserver::handle_request(const request& request)
{
    if (!isBusy)
    {
        cout << "Server " << serverID << " is processing request from "
             << request.get_IP_in() << " to " << request.get_IP_out()
             << " for " << request.get_process_time() << " cycles." << endl;
        
        isBusy = true;

        // simulate request processing time
        for (int i = 0; i < request.get_process_time(); i++)
        {
            //sleep(10);
        }

        cout << "Server " << serverID << " has completed processing the request." << endl;
        isBusy = false;
    } else {
        cout << "Server " << serverID << " is busy. Request from "
             << request.get_IP_in() << " to " << request.get_IP_out()
             << " is queued." << endl;
    }
}