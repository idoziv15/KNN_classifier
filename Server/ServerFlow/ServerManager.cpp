#include "ServerManager.h"
#include "IO/SocketIO.h"
#include "CLI.h"

/**
 * A constructor which receives a port number to bind to the server's main socket.
 * @param port The port number to bind.
 */
ServerManager::ServerManager(int port) {
    setPort(port);
}

/**
 * A default destructor.
 */
ServerManager::~ServerManager() = default;

/**
 * A setter for the port number to bind to the socket.
 * @param port The port number to bind to the socket.
 */
void ServerManager::setPort(int port) {
    this->portNum = port;
}

/**
 * A getter for the port of the server's socket.
 * @return The port number to bind to the socket.
 */
int ServerManager::getPort() {
    return this->portNum;
}

/**
 * Running the server without ever stopping, accepting new clients concurrently using threads.
 */
void ServerManager::runServer() {
    // Creating a socket creator.
    SocketCreator socketCreator(getPort());
    // Creating new server socket.
    int serverSocket = socketCreator.creatServerSocket();
    // Running the server.
    while (true) {
        // Accepting new clients.
        int clientSocket = socketCreator.acceptClient(serverSocket);
        // Thead - HERE!!!
        // Creating new IO to communicate with the client.
        AbstractDefaultIO *socketIO = new SocketIO(clientSocket);
        // Creating cli.
        CLI cli(socketIO);
        // Starting the conversation.
        cli.start();
        // Closing the client's socket.
        close(clientSocket);
        // Destroy the default io when finishing the connection.
        delete cli.getDefaultIO();
    }
}
