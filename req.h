#ifndef REQ_H
#define REQ_H

#include <string>

using namespace std;

class Request {

    public:
        Request();
        string ipI; // ip in
        string ipO; // ip out
        int randTime; // random time

};

#endif