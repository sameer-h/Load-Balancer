#include <iostream>
#include <limits.h>
#include <string>
#include <queue>

#include "lb.h"


/**
 * Returns current time of load balancer
 * @return time, int type
 */
int LoadBal::getTime() {

    return time;

}

/**
 * Returns size of the queue
 * @return reqQueue size, int type
 */
int LoadBal::getQueueSize() {
    return reqQueue.size();
}

/**
 * Default load balancer constructor
 */
LoadBal::LoadBal() {
    time = 0;
}

/**
 * Increases load balancer time by 1
 */
void LoadBal::incTime() {
    time+=1;
}

/**
 * Pushes request to queue
 * @param Request object is pushed to queue
 */
void LoadBal::pushReq(Request req) {
    reqQueue.push(req);
    incTime();
}

/**
 * Returns true/false if reqQueue is empty
 * @return bool type; true if reqQueue is empty
 */
bool LoadBal::isQueueClear() {
    return reqQueue.empty();
}

/**
 * Gets request from queue, and removes from queue
 * @return Request type
 */
Request LoadBal::getReq() {
    incTime();
    if (!reqQueue.empty()) {
        Request next = reqQueue.front();
        reqQueue.pop();
        return next;
    }

    cout << "Error" << endl;
    exit(0);
}

