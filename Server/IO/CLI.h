#ifndef EX4_CLI_H
#define EX4_CLI_H

#include <cstdlib>
#include <string>
#include <map>
#include "AbstractDefaultIO.h"
#include "StandardIO.h"
#include "../Commands/Commander.h"
#include "../Commands/AlgorithmSetting.h"
#include "../Commands/ClassifyData.h"
#include "../Commands/EndConnection.h"
#include "../Commands/SendData.h"
#include "../Commands/SendToDownload.h"
#include "../Commands/UploadFile.h"

using namespace std;

class CLI {
public:
    void start();

    CLI();

    explicit CLI(int clientSocket);

    ~CLI();

    void setClientSocket(int socket);

    int getClientSocket();

    string menuCreator();

    map<string, Commander *> initializeCommands(AbstractDefaultIO *IO);

    void setCommands(map<string, Commander *> commands);

    map<string, Commander *> getCommands;

private:
    int clientSocket;
    map<string, Commander *> commands;
};

#endif //EX4_CLI_H
