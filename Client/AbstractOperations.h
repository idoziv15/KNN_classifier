#ifndef EX4_ABSTRACTOPERATIONS_H
#define EX4_ABSTRACTOPERATIONS_H

#include <IO/AbstractDefaultIO.h>
#include <cstdlib>
#include "string"
#include "iostream"
#include "sstream"

class AbstractOperations{
public:
     explicit AbstractOperations(AbstractDefaultIO *defaultIo);
     ~AbstractOperations();

    virtual void executeOp() = 0;

    void setDio(AbstractDefaultIO *defaultIo);
    AbstractDefaultIO* getDio();

private:
    AbstractDefaultIO *dio;
};
#endif //EX4_ABSTRACTOPERATIONS_H
