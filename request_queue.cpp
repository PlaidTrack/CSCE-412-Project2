#include "request_queue.h"

request_queue::request_queue() {}

void request_queue::add_request(request req)
{
    requests.push(req);
}

// gets request in front of queue and remove it
request request_queue::pop_request()
{
    request r = requests.front();
    requests.pop();

    return r;
}

bool request_queue::is_empty()
{
    return requests.empty();
}