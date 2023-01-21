#ifndef EX4_ABSTRACTOPERATIONS_H
#define EX4_ABSTRACTOPERATIONS_H


#include "iostream"
#include "sstream"
#include "Client/IO/AbstractDefaultIO.h"
#include "Client/DataAndCalcs/ClientValidation.h"


class AbstractOperations {
public:
    explicit AbstractOperations(AbstractDefaultIO *defaultIo);

    virtual ~AbstractOperations();

    virtual void executeOp() = 0;

    void setDio(AbstractDefaultIO *defaultIo);

    AbstractDefaultIO *getDio();

    string userInput();

protected:
    AbstractDefaultIO *dio;
    ClientValidation clientValidations;
};

#endif //EX4_ABSTRACTOPERATIONS_H
