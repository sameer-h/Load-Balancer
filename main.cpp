#include <iostream>
#include <vector>
#include "req.h"
#include "lb.h"
#include "webserver.h"
#include "time.h"
#include "limits.h"

using namespace std;


Request makeReq() {
    Request newReq;
    newReq.randTime++;
    return newReq;
}

int main () {

    srand(time(0));

    int numReqs = 0;
    int numServers = 0;
    int runtime = 0;

    cout << "Enter the number of servers:" << endl;
    cin >> numServers;

    numReqs = numServers * 2;

    cout << "Enter the amount of time the load balancer should run:" << endl;
    cin >> runtime;

    LoadBal loadBal = LoadBal();

    for (int i = 0; i < numReqs; i++) {

        Request randReq = makeReq();
        loadBal.pushReq(randReq);

  
    }


    cout << "Queue Initial Size: " << loadBal.getQueueSize() << endl;

    vector<Webserver> serverVect(numServers, NULL);

    for (int i = 0; i < numServers; i++) {
        serverVect[i] = Webserver((char)(65 + i));
        serverVect[i].processReq(loadBal.getReq(), loadBal.getTime());

    }

    while (loadBal.getTime() < runtime) {


        if (loadBal.isQueueClear()) {
            cout << "QUEUE IS CLEAR. EXITING..." << endl;
            break;
        }

        int curTime = loadBal.getTime();


        if (serverVect[curTime % numServers].reqStatus(curTime)) {

            Request r = serverVect[curTime % numServers].getReq();
            cout << serverVect[curTime % numServers].getWebserverName() << " has processed from " << r.ipI << " to " << r.ipO << " at T = " << curTime << endl;
            serverVect[curTime % numServers].processReq(loadBal.getReq(), curTime);
        }

        if (rand() % 15 == 0) {
            Request randReq = makeReq();
            loadBal.pushReq(randReq);
        }

        loadBal.incTime();
    }

    cout << "Queue Final Size: " << loadBal.getQueueSize() << endl;
 
    return 0;

}