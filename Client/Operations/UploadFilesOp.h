#ifndef EX4_UPLOADFILESOP_H
#define EX4_UPLOADFILESOP_H
#include "Client/Operations/AbstractOperations.h"

class UploadFilesOp : public AbstractOperations{
public:
    void executeOp() override;

    string uploadFile(string path);

    bool createSendFile();


};
#endif //EX4_UPLOADFILESOP_H
