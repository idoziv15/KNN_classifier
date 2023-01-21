#include "SocketCreator.h"

/**
 * A constructor which sets a port number of a server's app.
 * @param port The server's app port number.
 */
SocketCreator::SocketCreator(int port) {
    setPort(port);
}

/**
 * A default destructor.
 */
SocketCreator::~SocketCreator() = default;


/**
 * A setter for the port number to bind to the socket.
 * @param port The port number to bind to the socket.
 */
void SocketCreator::setPort(int port) {
    this->portNum = port;
}

/**
 * A getter for the port of the server's socket.
 * @return The port number to bind to the socket.
 */
int SocketCreator::getPort() {
    return this->portNum;
}

/**
 * Creat a sockaddr_in for the server's socket.
 * @return struct of sockaddr_in.
 */
struct sockaddr_in SocketCreator::createAddrInStructServer() {
    // Create a struct for the socket's data.
    struct sockaddr_in sin{};
    // Set values to it of it's size (in bytes).
    memset(&sin, 0, sizeof(sin));
    // Set the protocol of the connection to the struct.
    sin.sin_family = AF_INET;
    // Set the addresses values of the socket.
    sin.sin_addr.s_addr = INADDR_ANY;
    // Get the current port.
    const int serverPort = getPort();
    // Set the current port of the server to the struct.
    sin.sin_port = htons(serverPort);
    return sin;
}


/**
 * Creat a sockaddr_in for the server's socket.
 * @return struct of sockaddr_in.
 */
struct sockaddr_in SocketCreator::createAddrInStructClient(const string& ip) {
    // Create a struct for the socket's data.
    struct sockaddr_in sin{};
    // Set values to it of it's size (in bytes).
    memset(&sin, 0, sizeof(sin));
    // Set the protocol of the connection to the struct.
    sin.sin_family = AF_INET;
    // Reformat the ip from string to char*.
    const char * ipAddr = ip.c_str();
    // Set the addresses values of the socket.
    sin.sin_addr.s_addr = inet_addr(ipAddr);
    // Get the current port.
    const int serverPort = getPort();
    // Set the current port of the server to the struct.
    sin.sin_port = htons(serverPort);
    return sin;
}


/**
 * Binding a socket to a port number.
 * @param port The port number to bind.
 * @param sin The struct number to bind.
 * @return the socket after binding.
 */
int SocketCreator::bindSocket(int serverSocket, sockaddr_in sin) {
    if (bind(serverSocket, (struct sockaddr *) &sin, sizeof(sin)) < ZERO_FLAG) {
        // If the binding didn't work, raise an error.
        perror("Error binding socket.");
        exit(0);
    }
    return serverSocket;
}

/**
 * Setting a given socket to listen to a specific number of client.
 * @param numOfListens The number of client to listen.
 * @return The socket after setting.
 */
int SocketCreator::setListen(int numOfListens, int serverSocket) {
    // Set the socket to listen to only 5 client in a row.
    if (listen(serverSocket, numOfListens) < ZERO_FLAG) {
        // If the set didn't work, rise an error.
        perror("Error listening to a socket.");
        exit(0);
    }
    return serverSocket;
}

/**
 * Responsible to create the server's socket.
 * @return The server's socket.
 */
int SocketCreator::creatServerSocket() {
    // Create a new socket.
    int serverSocket = makeNewSocket();
    struct sockaddr_in sin = createAddrInStructServer();
    // Bind the struct with all data to the server's socket, check if the binding worked.
    serverSocket = bindSocket(serverSocket, sin);
    // Set the server to listen to a specific number of client's.
    serverSocket = setListen(CLIENTS_TO_LISTEN, serverSocket);
    return serverSocket;
}

/**
 * Creating a new socket.
 * @return An int representing a socket.
 */
int SocketCreator::makeNewSocket() {
    // Creat a new socket.
    int newSocket = socket(AF_INET, SOCK_STREAM, 0);
    // If the creation didn't work, raise an error.
    if (newSocket < ZERO_FLAG) {
        perror("Error binding socket.");
        exit(0);
    }
    return newSocket;
}


/**
 * Accept a new client from a server's socket.
 * @param serverSocket The server's socket.
 * @return a socket of a new  client.
 */
int SocketCreator::acceptClient(int serverSocket) {
    // Create a struct for an incoming client.
    struct sockaddr_in client_sin{};
    // Set the size of the struct.
    unsigned int addr_len = sizeof(client_sin);
    // Accept a new client.
    int clientSocket = accept(serverSocket, (struct sockaddr *) &client_sin, &addr_len);
    // Check if the operation succeeded.
    if (clientSocket < ZERO_FLAG) {
        // If it didn't work, rise an error.
        perror("Error accepting client.");
        exit(0);
    }
    return clientSocket;
}


