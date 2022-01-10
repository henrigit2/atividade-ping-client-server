#include "Server.h"

void Server::createServer(){

    socket_conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(5000);

    if(socket_conn == -1){
        cout << "Socket Failed" << endl;
    }

    if(bind(socket_conn, (struct sockaddr*)&address, sizeof(address)) == -1){
        cout << "Bind Failed" << endl;
    }
}

void Server::listenServer(){
    if(listen(socket_conn, 1) == -1){
        cout << "Listen Failed" << endl;
    }

    int address_len = sizeof(address);

    newsocket_conn = accept(socket_conn, (struct sockaddr*)&address, (socklen_t*)&address_len);

    if(newsocket_conn == -1){
        cout << "Accept Failed" << endl;
    }
}

void Server::readServer(char *buffer){

    read(newsocket_conn, buffer, sizeof(buffer));

}

void Server::sendServer(char *buffer){

    send(newsocket_conn, buffer, sizeof(buffer), 0);

}

void Server::pingServer(){
    IMCPstruct pkt;
    ICMP icmp;

    char d[2];
    

    while(true){

        char buffer[2];
        this->readServer(buffer);
        icmp.decodeICMP(buffer, &pkt);
        cout << "ping(" << "type:" << pkt.type << "; code:" << pkt.code << ")" << endl;

        pkt.type = 0;
        pkt.code = 0;
        icmp.encodeICMP(pkt, d);
        this->sendServer(d);
        
    }
}

void Server::closeServer(){
    close(socket_conn);
}
