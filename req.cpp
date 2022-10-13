#include <iostream>
#include <limits.h>
#include <string>

#include "req.h"

using namespace std;

/**
 * Request object containing source & destination IP addresses as well as a time
 */
Request::Request() {

    ipI = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256); //!< Randomly generated Source IP Address 
    ipO = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256); //!< Randomly generated Destination IP Address 
    randTime = rand() % 500; //!< Randomly generated Time for Request 

}

