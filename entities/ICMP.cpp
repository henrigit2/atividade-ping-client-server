#include "ICMP.h"


void ICMP::encodeICMP(IMCPstruct pkt, char *buffer){
    buffer[0] = pkt.type + '0';
    buffer[1] = pkt.code + '0';
}

void ICMP::decodeICMP(char *buffer, IMCPstruct *pkt){
    pkt->type = buffer[0] - '0';
    pkt->code = buffer[1] - '0';
}