#ifndef ICMP_H
#define ICMP_H

#include <iostream>

using namespace std;

struct IMCPstruct
{
    int type;
    int code;
    //int checksum;
};

class ICMP {
    public:

        void encodeICMP(IMCPstruct pkt, char *buffer);
        void decodeICMP(char *buffer, IMCPstruct *pkt);
};







#endif