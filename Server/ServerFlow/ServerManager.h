#ifndef EX4_SERVERMANAGER_H
#define EX4_SERVERMANAGER_H

#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

#define CLIENTS_TO_LISTEN 5
#define DEFAULT_PORT 12345
#define ZERO_FLAG 0

/**
 *
 */
class ServerManager {
public:
    // Default constructor.
    ServerManager();

    // Default destructor.
    ~ServerManager();

    // Running the server.
    void runServer(int portNum);

    int makeNewSocket();
};

#endif //EX4_SERVERMANAGER_H
