#include <iostream>
#include <memory>
#include "server-client/Client.h"

using namespace std;

int main(){


    unique_ptr<Client> client(new Client);


    client->createClient();
    client->connectClient();
    client->pingClient();

    client->closeClient();

    client.reset();
    

    return 0;
}