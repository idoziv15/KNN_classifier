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
    cout << setting ;
    // Init a string for user input.
    string changeSetting, invalidServerReply;
    // Getting user input.
    getline(cin, changeSetting);
    // Send the user input to the server.
    getDio()->write(changeSetting);
}
