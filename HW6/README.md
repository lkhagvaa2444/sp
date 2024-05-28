Sure, here's a README.md file explaining the usage and purpose of the server-client system:

```markdown
# Multi-Threaded Server-Client System

This program implements a simple server-client system where the server can continuously accept commands and multiple clients can connect to view the server's commands and output.

## Usage

### Compilation

You can compile the server and client separately using `gcc` compiler.

Compile server.c:
```bash
gcc -o server server.c net.c -lpthread
```

Compile client.c:
```bash
gcc -o client client.c net.c
```

### Execution

1. Start the server by running the `server` executable:
   ```bash
   ./server <port>
   ```
   Replace `<port>` with the desired port number.

2. Connect clients to the server by running the `client` executable:
   ```bash
   ./client <port> <host>
   ```
   Replace `<port>` with the same port number used for the server, and `<host>` with the server's IP address or hostname.

3. Once connected, clients can send commands to the server, and the server's responses will be displayed to all connected clients.

4. To exit, enter "exit" command in the client terminal.

## Files

1. **server.c**: Contains the code for the server program that continuously accepts client connections and handles client requests in separate threads.

2. **client.c**: Contains the code for the client program that connects to the server and sends commands to it, displaying the server's responses.

3. **net.h** and **net.c**: Helper functions for network communication.

## Notes

- This program uses pthread library for multi-threading.
- The server handles each client connection in a separate thread to allow multiple clients to connect simultaneously.
- Clients can view all commands executed by the server and the corresponding output.
- Makefile is not provided, but the code can be compiled manually using gcc compiler as shown above.
```

This README.md file provides instructions on how to compile and use the server-client system, along with an overview of the files included in the project and some additional notes.