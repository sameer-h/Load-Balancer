#include <iostream>
#include <limits.h>
#include <string>
#include <queue>

#include "lb.h"


int LoadBal::getTime() {

    return time;

}

int LoadBal::getQueueSize() {
    return reqQueue.size();
}

LoadBal::LoadBal() {
    time = 0;
}

void LoadBal::incTime() {
    time+=1;
}

void LoadBal::pushReq(Request req) {
    reqQueue.push(req);
    incTime();
}

bool LoadBal::isQueueClear() {
    return reqQueue.empty();
}

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

