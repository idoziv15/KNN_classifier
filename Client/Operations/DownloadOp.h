#ifndef EX4_DOWNLOADOP_H
#define EX4_DOWNLOADOP_H

#include "AbstractOperations.h"
#include <thread>

class DownloadOp : public AbstractOperations {
public:
    // A constructor.
    explicit DownloadOp(AbstractDefaultIO *defaultIo);

    // A destructor.
    ~DownloadOp() override;

    // Making the operation.
    void executeOp() override;
};

#endif //EX4_DOWNLOADOP_H