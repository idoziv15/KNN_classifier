#include "AbstractOperations.h"

AbstractOperations::AbstractOperations(AbstractDefaultIO *defaultIo) {
    this->dio = defaultIo;
}

void AbstractOperations::setDio(AbstractDefaultIO *defaultIo) {
    this->dio = defaultIo;
}

AbstractDefaultIO *AbstractOperations::getDio() {
    return this->dio;
}

AbstractOperations::~AbstractOperations() = default;


/**
 * Reading the user's input.
 * @return The user's input.
 */
string AbstractOperations::userInput() {
    string line;
    getline(cin, line);
    return line;
}