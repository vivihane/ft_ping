#include "../includes/ft_ping.h"

// We use this function to calculate the checksum of the ICMP packet
// This means that we sum all the 16-bit words in the packet, and then take the one's complement of the result
// So we know that the checksum is correct if the sum of all the 16-bit words in the packet (including the checksum) is 0xFFFF
// And when we receive a packet, we can verify the checksum by calculating the checksum of the received packet and comparing it to the checksum in the packet

unsigned short checksum(void *b, int len) {
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}