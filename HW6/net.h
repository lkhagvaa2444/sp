#ifndef NET_H
#define NET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>

#define PORT 8080
#define SMAX 1024
#define TMAX 4096

typedef enum {
    TCP,
    UDP
} protocol_t;

typedef enum {
    SERVER,
    CLIENT
} mode_t;

typedef struct {
    int sock_fd;
    char serv_ip[INET_ADDRSTRLEN];
    int serv_port;
    mode_t mode;
} net_t;

void net_init(net_t *net, protocol_t protocol, mode_t mode, int port, const char *host);
void net_bind(net_t *net);
void net_listen(net_t *net);
int net_accept(net_t *net);
void net_connect(net_t *net);

#endif /* NET_H */
