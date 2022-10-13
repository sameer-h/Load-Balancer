#ifndef WEBSERVER_H
#define WEBSERVER_H

#include "req.h"
#include "iostream"

using namespace std;


class Webserver {

    private:

        Request req;
        int reqStartTime;
        char serverName;

    public:

        Webserver(char name);
        bool reqStatus(int curTime);
        void processReq(Request req, int curTime);
        char getWebserverName();
        Request getReq();

};

#endif