#ifndef EX4_ABSTRACTOPERATIONS_H
#define EX4_ABSTRACTOPERATIONS_H


#include "iostream"
#include "sstream"
#include "../../IO/AbstractDefaultIO.h"
#include "../DataAndCalcs/ClientValidation.h"

/**
 * A polymorphic class to gather oll client possible operations.
 */
class AbstractOperations {
public:
    // A constructor for the class.
    explicit AbstractOperations(AbstractDefaultIO *defaultIo);

    // A virtual destructor.
    virtual ~AbstractOperations();

    // A pure virtual "execute" method.
    virtual void executeOp() = 0;

    // A setter for the default io.
    void setDio(AbstractDefaultIO *defaultIo);

    // A getter for the default io.
    AbstractDefaultIO *getDio();

    // getting input from the user.
    string userInput();

protected:
    // The default io the class or its successor uses.
    AbstractDefaultIO *dio;
    // A client validation member.
    ClientValidation clientValidations;
};

#endif //EX4_ABSTRACTOPERATIONS_H
