#include "../includes/ft_ping.h"

// After checking the hostname and resolving it to an IP address, we need to create a raw socket to send ICMP packets to the destination.
// We use the socket() system call to create a raw socket with the AF_INET domain, SOCK_RAW type, and IPPROTO_ICMP protocol. 
// If the socket creation fails, we print an error message and exit the program.

int create_socket() {
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &(struct timeval){.tv_sec = 1}, sizeof(struct timeval));
    return sockfd;
}