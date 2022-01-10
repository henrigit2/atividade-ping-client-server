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

class Server {
    private:
        int socket_conn;
        int newsocket_conn;
        sockaddr_in address;

    public:
        void createServer();
        void listenServer();
        void readServer(char *buffer);
        void sendServer(char *buffer);
        void pingServer();
        void closeServer();
        //void Error(string erro);
};

#endif