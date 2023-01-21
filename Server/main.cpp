#include "Server/DataAndAssistance/ServerValidations.h"
#include "Server/ServerFlow/ServerManager.h"
/**
 * The main function of the server.
 * @return 0;
 */
int main(int args, char *argv[]) {
    // Creat a validation instance for the server's validation.
    ServerValidations serverValidations;
// Check if port and path are valid. if not, return.
    if(!serverValidations.validPortNumber(argv[1])){
        cout << "Port is not valid" << endl;
        return 0;
    }
    // Convert the port to an int.
    int port = stoi(argv[1]);
    ServerManager serverManager(port);
    serverManager.runServer();

    return 0;
}