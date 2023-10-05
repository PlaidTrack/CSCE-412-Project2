#ifndef REQUEST_H
#define REQUEST_H

#include <iostream>
#include <string>   // for IP obj
#include <ostream>
#include <cstdlib>  // random number generation

using namespace std;

/*
*Request object:
*   IP in
*   IP out
*   Process time
*/
class request
{
    private:
        string IP_in;
        string IP_out;
        int process_time;   // time in clock cycles
    public:
        request(const string& in, const string& out, int processingtime);  // default constructor

        // getters
        string get_IP_in() const { return IP_in; }
        string get_IP_out() const { return IP_out; }
        int get_process_time() const { return process_time; }

        static request generate_random_request();
};

#endif  // REQUEST_H