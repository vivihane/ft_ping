#ifndef FT_PING_H
#define FT_PING_H

#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

typedef struct s_ping {
    int sockfd;
    char *host;
    char ip_str[INET_ADDRSTRLEN];
    struct sockaddr_in dest_addr;
    int seq_num;
    int sent;
    int received;
    double rrt_min;
    double rrt_max;
    double rrt_sum;
    int verbose // option -v
} t_ping;

/* Forward declarations */
int create_socket();
void build_packet(char *packet, int seq_num);
void send_ping(t_ping *ping);
int receive_ping(t_ping *ping);
void ft_ping(t_ping *ping);
void resolve_host(t_ping *ping);
unsigned short checksum(void *b, int len);

#endif // FT_PING_H