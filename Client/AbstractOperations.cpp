#include "AbstractOperations.h"

AbstractOperations::AbstractOperations(AbstractDefaultIO *defaultIo) {
    setDio(defaultIo);
}

void AbstractOperations::setDio(AbstractDefaultIO *defaultIo) {
    this->dio = defaultIo;
}

AbstractDefaultIO *AbstractOperations::getDio() {
    return this->dio;
}

AbstractOperations::~AbstractOperations() = default;
