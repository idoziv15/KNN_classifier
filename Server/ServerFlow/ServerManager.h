#ifndef EX4_SERVERMANAGER_H
#define EX4_SERVERMANAGER_H

#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include "IO/SocketCreator.h"

#define CLIENTS_TO_LISTEN 5
#define DEFAULT_PORT 12345
#define ZERO_FLAG 0

/**
 *
 */
class ServerManager {
public:
    // Default constructor.
    ServerManager(int port);

    // Default destructor.
    ~ServerManager();

    // Running the server.
    void runServer();

private:

    int makeNewSocket();

    int creatServerSocket();

    struct sockaddr_in creatAddrInStruct();

    // A setter for the port number.
    void setPort(int port);

    // A getter for the port number.
    int getPort();

    // Binding a socket to a port number.
    int bindSocket(int serverSocket, sockaddr_in sin);

    // Set a socket to listen to a specific number of clients.
    int setListen(int numOfListens, int serverSocket);

    // Accepting a new client.
    int acceptClient(int serverSocket);

private:
    int portNum;
};

#endif //EX4_SERVERMANAGER_H
