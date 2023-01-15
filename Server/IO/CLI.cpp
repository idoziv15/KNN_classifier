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
    map<string, Commander *> commanders = initializeMap(new StandardIO());
}

string CLI::menuCreator() {
    return std::string();
}

map<string, Commander *> CLI::initializeCommands(AbstractDefaultIO *IO) {
    map<string, Commander *> initCommands;
    Commander *uploadFile = new UploadFile("upload an unclassified csv data file\n", IO);
    Commander *algorithmSetting = new AlgorithmSetting("algorithm setting\n", IO);
    Commander *classifyData = new ClassifyData("classify data\n", IO);
    Commander *displayResult = new SendData("display results\n", IO);
    Commander *downloadResult = new SendToDownload("download results\n", IO);
    Commander *exit = new EndConnection("exit\n", IO);

    initCommands["1"] = uploadFile;
    initCommands["2"] = algorithmSetting;
    initCommands["3"] = classifyData;
    initCommands["4"] = displayResult;
    initCommands["5"] = downloadResult;
    initCommands["8"] = exit;

    return initCommands;
}

void CLI::setCommands(map<string, Commander *> commands) {

}


