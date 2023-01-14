#ifndef EX4_UPLOADFILE_H
#define EX4_UPLOADFILE_H

#include "Commander.h"
#include "DataProcessing.h"
#include <utility>

/*
 * UploadFile class - a command that upload file using a IO tool to create a database.
 */
class UploadFile : public Commander {
public:
    // Constructor for UploadFIle class.
    UploadFile(string description, AbstractDefaultIO *newDescription);

    // Destructor for UploadFile class.
    ~UploadFile();

    // An implementation for the commander execute.
    void execute() override;

    vector<RelativeVector *> creatUnclassifiedRelatives(vector<vector<string>> lines);
    vector<ClassifiedRelativeVector *> creatClassifiedRelatives(vector<vector<string>> lines);


private:
    // dataProcessing object.
    DataProcessing dataProcessing;

};

#endif //EX4_UPLOADFILE_H
