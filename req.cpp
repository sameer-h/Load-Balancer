#include <iostream>
#include <limits.h>
#include <string>

#include "req.h"

using namespace std;

Request::Request() {

    ipI = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256); 
    ipO = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256); 
    randTime = rand() % INT_MAX; 

}
