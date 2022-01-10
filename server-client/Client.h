#ifndef SERVER_H
#define SERVER_H

#include <iostream>
#include <sys/socket.h>
#include <string.h>
#include <netinet/ip_icmp.h>
#include <netinet/in.h>
#include <unistd.h>
#include <memory>
#include "../entities/ICMP.h"



using namespace std;

class Client {
    private:
        int socket_conn;
        sockaddr_in address;

    public:
        void createClient();
        void connectClient();
        void readClient(char *buffer);
        void sendClient(char *buffer);
        void pingClient();
        void closeClient();
        //void Error(string erro);
};

#endif