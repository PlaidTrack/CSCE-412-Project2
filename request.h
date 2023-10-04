#ifndef REQUEST_H
#define REQUEST_H

#include <string>

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

        string generate_IP();
        int generate_time;
    private:
        string IP_in;
        string IP_out;
        int process_time;
};

#endif  // REQUEST_H