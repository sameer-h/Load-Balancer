#include "webserver.h"
using namespace std;

/**
 * Default webserver constructor that is initialized to have a char as name
 */
Webserver::Webserver(char c) {
    serverName = c;
    reqStartTime = 0;
}

/**
 * Allows server to process requests
 * @param req_, Request object to be processed
 * @param curTime, Current time the request was sent
 */
void Webserver::processReq(Request req_, int curTime) {

    req = req_;
    reqStartTime = curTime;

}

/**
 * Returns whether a request has finished
 * @param curTime, Current time
 * @return if request is done, bool type returns true
 */
bool Webserver::reqStatus(int curTime) {

    if (curTime >= (reqStartTime + req.randTime)) {
        return true;
    } 

    return false;

}

/**
 * Returns name of server
 * @return name of server, char type
 */
char Webserver::getWebserverName() {
    return serverName;
}

/**
 * Returns request from server
 * @return request currently being processed
 */
Request Webserver::getReq() {
    return req;
}

