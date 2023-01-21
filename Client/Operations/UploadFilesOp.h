#ifndef EX4_UPLOADFILESOP_H
#define EX4_UPLOADFILESOP_H

#include "AbstractOperations.h"

/**
 * Uploading a file to the program.
 */
class UploadFilesOp : public AbstractOperations {
public:

    // A constructor for the class receiving a default io.
    explicit UploadFilesOp(AbstractDefaultIO *defaultIo);

    // A destructor for the class.
    ~UploadFilesOp() override;

    // Execute the command.
    void executeOp() override;

    // Upload a file.
    string uploadFile(string path);

    // Creating a string from a file content and sending it to the server.
    bool createSendFileOne();

    bool createSendFileTwo();
};

#endif //EX4_UPLOADFILESOP_H
