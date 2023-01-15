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

    explicit CLI(AbstractDefaultIO *defaultIo);

    ~CLI();

    void setDefaultIO(AbstractDefaultIO* IO);

    AbstractDefaultIO* getDefaultIO();

    string menuCreator();

    map<string, Commander *> initializeCommands(AbstractDefaultIO *IO);

    void setCommands(map<string, Commander *> newCommand);

    map<string, Commander *> getCommands();

    Commander* processRequest(const string& clientChoice);

private:
    AbstractDefaultIO* defaultIo;
    map<string, Commander *> commands;
};

#endif //EX4_CLI_H
