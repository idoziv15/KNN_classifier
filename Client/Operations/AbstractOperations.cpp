#include "AbstractOperations.h"

/**
 * A constructor receiving a default IO.
 * @param defaultIo The IO sent to it.
 */
AbstractOperations::AbstractOperations(AbstractDefaultIO *defaultIo) {
    setDio(defaultIo);
}

/**
 * A default destructor.
 */
AbstractOperations::~AbstractOperations() = default;

/**
 * A setter for the default io.
 * @param defaultIo The new default io.
 */
void AbstractOperations::setDio(AbstractDefaultIO *defaultIo) {
    this->dio = defaultIo;
}

/**
 * A getter for the default io.
 * @return The current default io.
 */
AbstractDefaultIO *AbstractOperations::getDio() {
    return this->dio;
}

/**
 * Reading the user's input.
 * @return The user's input.
 */
string AbstractOperations::userInput() {
    string line;
    getline(cin, line);
    return line;
}
