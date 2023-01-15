//
// Created by yuval on 1/15/23.
//

#include "CLI.h"

CLI::~CLI() = default;

CLI::CLI() = default;

CLI::CLI(int clientSocket) {
    setClientSocket(clientSocket);
}

void CLI::setClientSocket(int socket) {
    this->clientSocket = socket;
}

int CLI::getClientSocket() {
    return this->clientSocket;
}

void CLI::start() {

}

string CLI::menuCreator() {
    return std::string();
}

map<string, Commander *> CLI::initializeMap() {
    map<string, Commander *> initCommands;
    StandardIO standardIo;
    UploadFile uploadFile = new UploadFile()

}

void CLI::setCommands(map<string, Commander *> commands) {

}


