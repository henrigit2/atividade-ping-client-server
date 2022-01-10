#include <iostream>
#include <memory>
#include "server-client/Server.h"

using namespace std;

int main(){


    unique_ptr<Server> server(new Server);

    server->createServer();
    server->listenServer();
    server->pingServer();
    
    server->closeServer();

    server.reset();
    

    return 0;
}