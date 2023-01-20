#ifndef EX4_CLIENTMANAGEMENT_H
#define EX4_CLIENTMANAGEMENT_H

#include "IO/AbstractDefaultIO.h"
#include <cstdlib>
#include "Client/Operations/AbstractOperations.h"
#include "Client/DataAndCalcs/ClientValidation.h"
#include "IO/SocketCreator.h"


using namespace std;

/**
 * This class is responsible to manage all data and flow regard to the client.
 */
class ClientManagement {
public:

    // A constructor for the class.
    ClientManagement(int port, string ip);

    // A constructor which receives a default io pointer.
    explicit ClientManagement(AbstractDefaultIO *dio);

    void setPort(int newPort);

    int getPort();

    void setIp(string serverIp);

    string getIp();

    // A destructor for the class.
    ~ClientManagement();

    void start();


    // A setter for the default io.
    void setDefaultIO(AbstractDefaultIO *dio);

    // A getter for the default io.
    AbstractDefaultIO *getDefaultIO();

    // Managing the menu choice of the client.
    bool menuManagement(string menuStr);

    // Reading input from the user.
    string userInput();

    // Processing the user's choice.
    AbstractOperations *choiceProcess(string choice);

    // Runs the connection.
    void run();

private:
    // IO member.
    AbstractDefaultIO *defaultIo{};
    // The client management member.
    ClientValidation clientValidation;
    // The port number of the server.
    int port;
    // The server's ip.
    string serverIp;
};

#endif //EX4_CLIENTMANAGEMENT_H
