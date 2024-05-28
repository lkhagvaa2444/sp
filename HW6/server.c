#include "net.h"
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex for thread synchronization

// Function to handle client requests
void *handle_client(void *arg) {
    int connfd = *(int *)arg;
    close(STDOUT_FILENO);                    // Close stdout
    dup2(connfd, STDOUT_FILENO);             // Redirect stdout to connfd
    dup2(connfd, STDERR_FILENO);             // Redirect stderr to connfd
    while (1) {
        char cmd[SMAX];
        int len = read(connfd, cmd, SMAX);   // Read command from client
        if (len <= 0) break;                 // If nothing read, break
        strtok(cmd, "\n");                   // Remove newline character
        fprintf(stderr, "cmd=%s\n", cmd);    // Print command for observation
        if (strncmp(cmd, "exit", 4) == 0)    // If command is "exit", break
            break;
        pthread_mutex_lock(&mutex);          // Lock mutex before system call
        system(cmd);                         // Execute the command
        pthread_mutex_unlock(&mutex);        // Unlock mutex after system call
        write(connfd, "\n", 1);              // Respond to client
    }
    close(connfd);            // Close connection
    return NULL;
}

int main(int argc, char *argv[]) {
    int port = (argc >= 2) ? atoi(argv[1]) : PORT;
    net_t net;
    net_init(&net, TCP, SERVER, port, NULL);
    net_bind(&net);
    net_listen(&net);
    while(1) { // Main loop: Wait for clients to connect and handle them in separate threads
        int connfd = net_accept(&net); // Wait for connection
        assert(connfd >= 0);
        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, (void *)&connfd); // Create thread to handle client
    }
}
