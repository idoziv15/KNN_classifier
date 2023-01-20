#ifndef EX4_DISPLAYRESULT_H
#define EX4_DISPLAYRESULT_H

#include "AbstractOperations.h"

class DisplayResult : public AbstractOperations {
    explicit DisplayResult(AbstractDefaultIO *defaultIo);

    ~DisplayResult();

    void executeOp() override;
};


#endif //EX4_DISPLAYRESULT_H
