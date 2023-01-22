#ifndef EX4_SERVERMANAGER_H
#define EX4_SERVERMANAGER_H

#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include "../../IO/SocketCreator.h"
#include "../../IO/SocketIO.h"
#include "CLI.h"
#include <thread>

#define CLIENTS_TO_LISTEN 5
#define DEFAULT_PORT 12345
#define ZERO_FLAG 0

/**
 * Running the server.
 */
class ServerManager {
public:
    // Default constructor.
    explicit ServerManager(int port);

    // Default destructor.
    ~ServerManager();

    // Running the server.
    void runServer();

    // A setter for the port number.
    void setPort(int port);

    // A getter for the port number.
    int getPort();


private:

    //The port number we got as argument to the program.
    int portNum{};
};

#endif //EX4_SERVERMANAGER_H
