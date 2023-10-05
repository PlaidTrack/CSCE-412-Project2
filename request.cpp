#include "request.h"

// request constructor
request::request(const string& in, const string& out, int processingtime)
{
    this->IP_in = in;
    this->IP_out = out;

    // to ensure it's at least 3 cycles
    this->process_time = (processingtime < 3) ? 3 : processingtime;
}


// creates random IP addresses in the IPv4 format
request request::generate_random_request()
{
    // random IP addresses
    string src_address = to_string(rand() % 127) + "." + to_string(rand() % 127) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
    string dest_address = to_string(rand() % 127) + "." + to_string(rand() % 127) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
    int processingtime = 3 + rand() % 8;  // time set between 3-10 cycles

    return request(src_address, dest_address, processingtime);
}