#include "webserver.h"
using namespace std;

Webserver::Webserver(char c) {
    serverName = c;
    reqStartTime = 0;
}

void Webserver::processReq(Request req_, int curTime) {

    req = req_;
    reqStartTime = curTime;

}

bool Webserver::reqStatus(int curTime) {

    if (curTime >= (reqStartTime + req.randTime)) {
        return true;
    } 

    return false;

}

char Webserver::getWebserverName() {
    return serverName;
}

Request Webserver::getReq() {
    return req;
}

