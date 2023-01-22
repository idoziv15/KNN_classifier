#ifndef EX4_DISPLAYRESULT_H
#define EX4_DISPLAYRESULT_H

#include "AbstractOperations.h"

/**
 * An operation responsible to display the result of the classification received from the server..
 */
class DisplayResult : public AbstractOperations {
public:
    // A constructor for the class.
    explicit DisplayResult(AbstractDefaultIO *defaultIo);

    // A default destructor.
    ~DisplayResult() override;

    // An implementation for the execute operation.
    void executeOp() override;
};

#endif //EX4_DISPLAYRESULT_H
