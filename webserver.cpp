//webserver.cpp

#include "webserver.h"

webserver::webserver(string name)
{
    server_name = name;
}

void webserver::handle_request(request r, int timestamp)
{
    current_request = r;
    current_wait = timestamp;
}