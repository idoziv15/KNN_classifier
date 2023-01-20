#ifndef EX4_DOWNLOADOP_H
#define EX4_DOWNLOADOP_H

#include "AbstractOperations.h"

class DownloadOp : public AbstractOperations {
public:
    // A constructor.
    explicit DownloadOp(AbstractDefaultIO *defaultIo);
    ~DownloadOp();

    // Making the operation.
    void executeOp() override;

    // Downloading the file to the computer.
    void downloadFileToComputer(string file);
};

#endif //EX4_DOWNLOADOP_H
