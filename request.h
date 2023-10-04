#ifndef REQUEST_H
#define REQUEST_H

#include <string>   // for IP obj
#include <ostream>

using namespace std;

/*
*Request Obj:
*   IP in
*   IP out
*   Process time
*/
class request
{
    public:
        request();  // default constructor

        // getters
        string get_IP_in()  { return IP_in; }
        string get_IP_out() { return IP_out; }
        int get_process_time() { return process_time; }

        string generate_IP();
        int generate_time();
    private:
        string IP_in;
        string IP_out;
        int process_time;
};

#endif  // REQUEST_H