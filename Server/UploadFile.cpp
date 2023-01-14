//
// Created by tal on 1/14/23.
//

#include "UploadFile.h"

#include <utility>


/*
 * Constructor for UploadFile class.
 */
UploadFile::UploadFile(string description, AbstractDefaultIO *newDescription)
        : Commander(std::move(description), newDescription) {

}

/*
 * Destructor for UploadFile class.
 */
UploadFile::~UploadFile() = default;


/*
 * Control flow function.
 */
void UploadFile::execute() {

    string userUnclassifiedFile = getDio()->read();
//    string userClassifiedFile = getDio()->read();
    vector<string> unclassifiedVector = this->dataProcessing.catchDelim(userUnclassifiedFile, '\n');
    vector<vector<string>> lines = this->dataProcessing.createLinesArray(unclassifiedVector);
    vector<vector<double>> doublesVec = this->dataProcessing.linesToDoubles(lines);
    vector<RelativeVector*> unclassifiedFile = this->dataProcessing.doublesToRelatives(doublesVec);










}


