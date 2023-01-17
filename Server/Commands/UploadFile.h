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

    // Creating unclassified relative vector from vector that contains vectors of strings.
    vector<RelativeVector *> creatUnclassifiedRelatives(vector<vector<string>> lines);

    // Creating classified relative vector from vector that contains vectors of strings.
    vector<ClassifiedRelativeVector *> creatClassifiedRelatives(vector<vector<string>> lines);

    // Getting the classification of the classified data.
    void extractClassifications(vector<vector<string>> &lines, vector<string> &classifications);
};

#endif //EX4_UPLOADFILE_H
