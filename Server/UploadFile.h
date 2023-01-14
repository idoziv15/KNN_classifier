#ifndef EX4_UPLOADFILE_H
#define EX4_UPLOADFILE_H
#include "Commander.h"
class UploadFile: public Commander{
public:
    UploadFile(string description, AbstractDefaultIO *newDescription);
    ~UploadFile();
    void execute() override;

};
#endif //EX4_UPLOADFILE_H
