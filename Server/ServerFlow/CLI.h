#ifndef EX4_CLI_H
#define EX4_CLI_H

#include <cstdlib>
#include <string>
#include <map>
#include "./IO/AbstractDefaultIO.h"
#include "./IO/StandardIO.h"
#include "Server/Commands/Commander.h"
#include "Server/Commands/AlgorithmSetting.h"
#include "Server/Commands/ClassifyData.h"
#include "Server/Commands/EndConnection.h"
#include "Server/Commands/SendData.h"
#include "Server/Commands/SendToDownload.h"
#include "Server/Commands/UploadFile.h"

using namespace std;
/**
 * CLI class - The control flow of the server, running all the command by user's choice.
 */
class CLI {
public:
    // The control flow method.
    void start();

    // The default constructor for CLI class.
    CLI();

    // Constructor CLI class.
    explicit CLI(AbstractDefaultIO *defaultIo);

    // Destructor for CLI class.
    ~CLI();

    // Setter for IO.
    void setDefaultIO(AbstractDefaultIO* IO);

    // Getter for IO.
    AbstractDefaultIO* getDefaultIO();

    // Creating the menu for the client.
    string menuCreator();

    // Creating a map that contain all the commands.
    map<string, Commander *> initializeCommands(AbstractDefaultIO *IO);

    // Setter for the specific command.
    void setCommands(map<string, Commander *> newCommand);

    // Getter for the command.
    map<string, Commander *> getCommands();

    // This method checking the user choice and process is request.
    Commander* processRequest(string clientChoice);

private:
    // IO member.
    AbstractDefaultIO* defaultIo;

    // Map for all the commands.
    map<string, Commander *> commands;
};

#endif //EX4_CLI_H
