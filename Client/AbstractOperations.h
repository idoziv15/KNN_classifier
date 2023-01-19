#ifndef EX4_ABSTRACTOPERATIONS_H
#define EX4_ABSTRACTOPERATIONS_H

#include <IO/AbstractDefaultIO.h>

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
