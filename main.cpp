#include <iostream>
#include "req.h"
#include "lb.h"
#include "webserver.h"
#include <vector>


using namespace std;

int main () {


    int numReqs = 0;
    int numServers = 0;
    int runtime = 0;


    cout << "Enter the number of servers:" << endl;
    cin >> numServers;

    numReqs = numServers * 2;

    cout << "Enter the amount of time the load balancer should run:" << endl;
    cin >> runtime;

    Request req;
    cout << "IP IN: " << req.ipI << endl;
    cout << "IP OUT: " << req.ipO << endl;
    cout << "IP TIME: " << req.randTime << endl;

    LoadBal loadBal = LoadBal();

    for (int i = 0; i < numReqs; i++) {

        Request randReq;
        loadBal.pushReq(randReq);
  
    }

    vector<Webserver> serverVect(numServers, NULL);

  
 
    return 0;

}