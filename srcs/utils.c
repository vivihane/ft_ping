#include "../includes/ft_ping.h"

void domain_to_ip(const char *domain, char *ip) {
    struct addrinfo hints, *res;
    int status;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET; // Use AF_INET for IPv4
    hints.ai_socktype = SOCK_STREAM; // Use SOCK_STREAM for TCP

    if ((status = getaddrinfo(domain, NULL, &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in *ipv4 = (struct sockaddr_in *)res->ai_addr;
    inet_ntop(AF_INET, &(ipv4->sin_addr), ip, INET_ADDRSTRLEN);

    freeaddrinfo(res);
}