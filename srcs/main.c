#include <stdio.h>
#include "../includes/ft_ping.h"

int main(int argc, char *argv[]) {
    if (argc > 3 || argc < 2) {
        printf("Usage: %s <destination>\n", argv[0]);
        return 1;
    }
    while (1) {
        ft_ping(argv[1]);
    }
    return 0;
}