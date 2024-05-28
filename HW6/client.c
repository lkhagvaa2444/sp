#include "net.h"

int main(int argc, char *argv[]) {
    int port = (argc >= 2) ? atoi(argv[1]) : PORT;
    char *host = (argc >= 3) ? argv[2] : "localhost";
    net_t net;
    net_init(&net, TCP, CLIENT, port, host);
    net_connect(&net);
    char cmd[SMAX], recvBuff[TMAX], op[SMAX];
    printf("Connected to server %s!\n", net.serv_ip);
    while (1) { // Main loop: Wait for user input, send requests to server, and display responses
        printf("%s $ ", net.serv_ip);           // Print prompt
        fgets(cmd, SMAX, stdin);                // Wait for user input
        write(net.sock_fd, cmd, strlen(cmd));   // Send command to server

        sscanf(cmd, "%s", op);                  // Get command
        if (strncmp(op, "exit", 4) == 0) break; // If command is "exit", break

        sleep(1);                               // Sleep for 1 second
        int n = read(net.sock_fd, recvBuff, TMAX-1); // Read server response
        assert(n > 0);
        recvBuff[n-1] = '\0';                   // Null-terminate the string
        puts(recvBuff);                         // Display response
    }
    close(net.sock_fd);
    return 0;
}
