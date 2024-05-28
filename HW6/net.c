#include "net.h"

void net_init(net_t *net, protocol_t protocol, mode_t mode, int port, const char *host) {
    net->mode = mode;
    net->serv_port = port;
    if (host)
        strncpy(net->serv_ip, host, INET_ADDRSTRLEN);
    if (protocol == TCP) {
        net->sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    } else {
        net->sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    }
    assert(net->sock_fd >= 0);
}

void net_bind(net_t *net) {
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(net->serv_port);
    int bind_status = bind(net->sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    assert(bind_status != -1);
}

void net_listen(net_t *net) {
    int listen_status = listen(net->sock_fd, 10);
    assert(listen_status != -1);
}

int net_accept(net_t *net) {
    struct sockaddr_in cli_addr;
    socklen_t cli_len = sizeof(cli_addr);
    int connfd = accept(net->sock_fd, (struct sockaddr *)&cli_addr, &cli_len);
    assert(connfd >= 0);
    if (inet_ntop(AF_INET, &cli_addr.sin_addr, net->serv_ip, INET_ADDRSTRLEN) == NULL) {
        perror("inet_ntop");
        exit(EXIT_FAILURE);
    }
    return connfd;
}

void net_connect(net_t *net) {
    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(net->serv_port);
    if (inet_pton(AF_INET, net->serv_ip, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(EXIT_FAILURE);
    }
    int connect_status = connect(net->sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    assert(connect_status != -1);
}
