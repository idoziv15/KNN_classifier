#ifndef EX4_UPLOADFILE_H
#define EX4_UPLOADFILE_H

#include "Commander.h"
#include "Server/DataAndAssistance/DataProcessing.h"
#include <utility>

/*
 * UploadFile class - a command that upload file using a IO tool to create a database.
 */
class UploadFile : public Commander {
public:
    // Constructor for UploadFIle class.
    UploadFile(string description, AbstractDefaultIO *Dio);

    // Destructor for UploadFile class.
    ~UploadFile();

    // An implementation for the commander execute.
    void execute() override;

    vector<RelativeVector *> creatUnclassifiedRelatives(vector<vector<string>> lines);

    vector<ClassifiedRelativeVector *> creatClassifiedRelatives(vector<vector<string>> lines);

    vector<string> extractClassifications(vector<vector<string>> &lines);


};

#endif //EX4_UPLOADFILE_H
