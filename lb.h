#ifndef LB_H
#define LB_H

#include "req.h"
#include <queue>


class LoadBal {

    public:
        int getTime();
        int getQueueSize();
        LoadBal();
        bool isQueueClear();
        void incTime();
        void pushReq(Request req);
        Request getReq();

    private:
        queue<Request> reqQueue;
        int time;

};



#endif