#include "AlgorithmSettingOp.h"

/**
 * A constructor for AlgorithmSettingOp class.
 * @param defaultIo socketIO.
 */
AlgorithmSettingOp::AlgorithmSettingOp(AbstractDefaultIO *defaultIo) : AbstractOperations(defaultIo) {

}

/**
 * A default destructor for AlgorithmSettingOp class.
 */
AlgorithmSettingOp::~AlgorithmSettingOp() = default;

/**
 *  This method run the algorithm setting option for the client.
 */
void AlgorithmSettingOp::executeOp() {

    // Get the server response.
    string setting = getDio()->read();
    // Printing the server response.
    cout << setting << endl;
    // Init a string for user input.
    string changeSetting, invalidServerReply;
    // Getting user input.
    getline(cin, changeSetting);
    // Concatenate the user input with $ for server check.
    changeSetting += "$";
    // Send the user input to the server.
    getDio()->write(changeSetting);
    // Checking if the server returned a valid flag for the user input, if valid return.
    if (getDio()->read() == "Valid") {
        return;
    }
    // Getting the invalid message from the server.
    invalidServerReply = getDio()->read();
    // Presenting the user the invalidation input message.
    cout << invalidServerReply << endl;

}
