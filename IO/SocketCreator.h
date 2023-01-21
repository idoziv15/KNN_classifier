#ifndef EX4_SOCKETCREATOR_H
#define EX4_SOCKETCREATOR_H

#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <string>

using namespace std;

#define CLIENTS_TO_LISTEN 5
#define DEFAULT_PORT 12345
#define ZERO_FLAG 0

class SocketCreator {
public:
    // A constructor for the class.
    explicit SocketCreator(int port);

    // A destructor for the class.
    ~SocketCreator();

    // Creating a new socket.
    int makeNewSocket();

    // Creating a new server socket.
    int creatServerSocket();

    // Creating a new struct for the server.
    struct sockaddr_in createAddrInStructServer();

    // Creating a new struct for the client, using the server's ip.
    struct sockaddr_in createAddrInStruct(const string& ip);

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
    // The port number of the server.
    int portNum;
};

#endif //EX4_SOCKETCREATOR_H
