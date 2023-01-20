#include "ServerManager.h"

ServerManager::ServerManager() = default;

ServerManager::~ServerManager() = default;



void ServerManager::runServer(int portNum) {
    int serverSocket = makeNewSocket();
}

/**
 * Creating a new socket.
 * @return An int representing a socket.
 */
int ServerManager::makeNewSocket() {
    // Creat a new socket.
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    // If the creation didn't work, raise an error.
    if (serverSocket < ZERO_FLAG) {
        perror("Error binding socket.");
        exit(0);
    }
    return serverSocket;
}
