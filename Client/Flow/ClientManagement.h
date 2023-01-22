#ifndef EX4_CLIENTMANAGEMENT_H
#define EX4_CLIENTMANAGEMENT_H


#include <cstdlib>
#include <utility>
# include "../../IO/SocketCreator.h"
#include "../../IO/SocketIO.h"
#include "../Operations/UploadFilesOp.h"
#include "../Operations/AlgorithmSettingOp.h"
#include "../Operations/DisplayResult.h"
#include "../Operations/DownloadOp.h"



using namespace std;

/**
 * This class is responsible to manage all data and flow regard to the client.
 */
class ClientManagement {
public:

    // Initiating the client's management to start running.
    void start();

    // A constructor for the class.
    ClientManagement(int port, string ip);

    // A constructor which receives a default io pointer.
    explicit ClientManagement(AbstractDefaultIO *dio);

    // A setter for the port number of the server.
    void setPort(int newPort);

    // A getter for the port number of the server.
    int getPort();

    // A setter for the IP number of the server.
    void setIp(string serverIp);

    // A getter for the IP number of the server.
    string getIp();

    // A destructor for the class.
    ~ClientManagement();

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
    int port = 12345;
    // The server's ip.
    string serverIp = "127.0.0.1";
};

#endif //EX4_CLIENTMANAGEMENT_H
