#include "Client.h"


void Client::createClient(){

    socket_conn = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(5000);

    if(socket_conn == -1){
        cout << "Socket Failed";
    }
}

void Client::connectClient(){
    if(connect(socket_conn, (struct sockaddr*)&address, sizeof(address)) < 0){
        cout << "Connect Failed" << endl;
    }
}

void Client::readClient(char *buffer){

    read(socket_conn, buffer, sizeof(buffer));

}

void Client::sendClient(char *buffer){

    send(socket_conn, buffer, sizeof(buffer), 0);

}

void Client::pingClient(){
    IMCPstruct pkt;
    ICMP icmp;

    char d[2];
    


    while(true){
    
        usleep(1000000);

        pkt.type = 8;
        pkt.code = 0;
        icmp.encodeICMP(pkt, d);
        this->sendClient(d);

        char buffer[2];
        this->readClient(buffer);
        icmp.decodeICMP(buffer, &pkt);
        cout << "ping(" << "type:" << pkt.type << "; code:" << pkt.code << ")" << endl;

        
        
    }
}

void Client::closeClient(){
    close(socket_conn);
}
