// webserver.cpp

#ifndef REQUEST_CPP
#include "request.cpp"
#endif

class webserver
{
    public:
        // default constructor
        webserver()
        {
            request_start_time = 0;
            server_name = ' ';
        }

        // overloaded constructor
        webserver(char c)
        {
            request_start_time = 0;
            server_name = c;
        }

        void add_request(request req, int curr_time)
        {
            r = req;
            request_start_time = curr_time;
        }

        // loadbalancer may need to know what request we're handling
        request get_request()
        {
            return r;
        }

        char get_name()
        {
            return server_name;
        }

        // checks if current request is complete
        bool is_request_done(int curr_time)
        {
            return (curr_time > (request_start_time + r.process_time));
        }

    private:
        request r;
        int request_start_time;
        char server_name;
}