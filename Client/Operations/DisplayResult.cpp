#include "DisplayResult.h"

/**
 * A constructor who receives a default io to initiate it's inheriting class.
 * @param defaultIo A default io for the class.
 */
DisplayResult::DisplayResult(AbstractDefaultIO *defaultIo) : AbstractOperations(defaultIo) {

}

/**
 * A default destructor.
 */
DisplayResult::~DisplayResult() = default;

/**
 * Executing the operation by printing the response from the server.
 */
void DisplayResult::executeOp() {
    cout << getDio()->read();
    getDio()->write("Ok");
}
