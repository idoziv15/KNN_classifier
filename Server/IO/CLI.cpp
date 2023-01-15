//
// Created by yuval on 1/15/23.
//

#include "CLI.h"

#include <utility>

CLI::~CLI() = default;

CLI::CLI() = default;

CLI::CLI(AbstractDefaultIO *IO) {
    setDefaultIO(IO);
}

void CLI::setDefaultIO(AbstractDefaultIO *IO) {
    this->defaultIo = IO;
}

AbstractDefaultIO *CLI::getDefaultIO() {
    return this->defaultIo;
}

void CLI::setCommands(map<string, Commander *> newCommand) {
    this->commands = std::move(newCommand);
}

map<string, Commander *> CLI::getCommands() {
    return this->commands;
}


void CLI::start() {
    AbstractDefaultIO *dIO = getDefaultIO();
    map<string, Commander *> commanders = initializeCommands(dIO);
    setCommands(commanders);
    string menu = menuCreator();
    while (true) {
        dIO->write(menu);
        string response = dIO->read();
        Commander* command = processRequest(response);
        if (command == nullptr){
            dIO->write("invalid input\n");
            continue;
        }
        command->execute();
        if (response == "8" || response == "8\n"){
            // Free recourses and close client socket!!!!!!!!!.
            break;
        }
    }

}

string CLI::menuCreator() {
    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    menu += "1. " + this->commands["1"]->getDescription();
    menu += "2. " + this->commands["2"]->getDescription();
    menu += "3. " + this->commands["3"]->getDescription();
    menu += "4. " + this->commands["4"]->getDescription();
    menu += "5. " + this->commands["5"]->getDescription();
    menu += "8. " + this->commands["8"]->getDescription();
    return menu;
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

Commander *CLI::processRequest(const string& clientChoice) {

    if (this->commands.find(clientChoice) == this->commands.end()){
        return nullptr;
    }
    return this->commands[clientChoice];
}



