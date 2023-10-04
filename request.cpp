#include <cstdlib>  // random number generation
#include <time.h>
#include <chrono>
#include <thread>

#include "request.h"

// request constructor
request::request()
{
    IP_in = generate_IP();
    IP_out = generate_IP();

    process_time = generate_time();
}

// creates random IP addresses in the IPv4 format
string request::generate_IP()
{
    string address = "";
    int octets[4] = {0,0,0,0};  // sections in IP address

    int rand_seed = (rand() % 1000);    // gets last 4 digits of random int

    int offset = 0;
    int range = 256;    //  each octet can be anywhere between 0 and 255

    for (int i = 0; i < 4; i++)
    {
        if (i==0)   // first octant range
        {
            offset = 1;
            range = 127; // first octant range is 1 - 126
        } else if (i == 3)  // last octant range
        {
            offset = 1;
            range = 255; // last octant range is 1 - 254
        }

        octets[i] = offset + (rand() % range);  // set octet within set range
        address += to_string(octets[i]);

        if (i < 3)
            address += "."; // divides each octet
    }

    return address;
}

// generate random time
int request::generate_time()
{
    // random seed
    int rand_seed = (rand() % 1000);
    srand(rand_seed);

    int time_limit = 3;
    int t = rand() % time_limit; // time it takes to complete request

    return t;
}