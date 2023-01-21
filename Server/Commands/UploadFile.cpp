#include "UploadFile.h"


/**
 * A constructor which pass the arguments he receives to the commander constructor.
 * @param description the description of the command.
 * @param Dio The default IO.
 * @param database The general database.
 */
UploadFile::UploadFile(string description, AbstractDefaultIO *Dio, RelativeDatabase *database)
        : Commander(std::move(description), Dio, database) {

}

/*
 * Destructor for UploadFile class.
 */
UploadFile::~UploadFile() = default;


/*
 * Control flow function.
 */
void UploadFile::execute() {
    // Delete all old classified files (if any).
    getDatabase()->deleteClassified();
    // Delete all old unclassified files (if any).
    getDatabase()->deleteUnclassified();

    // Asking from the user to upload the train file.
    getDio()->write("Please upload your local train CSV file.\n");
    // Reading a file of classified vectors.
    string classifiedFile = getDio()->read();
    if (classifiedFile == "fail") {
        getDio()->write("invalid input\n" + getMenu());
        return;
    }
    // Extracting each vector from the file to a vector of strings.
    vector<string> classifiedVector = this->dataProcessing.catchDelim(classifiedFile, '\n');
    // Extracting each cell in the line to a vector, and the vector to a vector.
    vector<vector<string>> classifiedLines = this->dataProcessing.createLinesArray(classifiedVector);
    // Creating a relative vector for the datastructures.
    vector<ClassifiedRelativeVector *> classifiedRelatives = creatClassifiedRelatives(classifiedLines);
    // Sending the client approval for his upload train file and asking for the test file.
    getDio()->write("Upload complete.\nPlease upload your local test CSV file.\n");

    // Reading a file of unclassified vectors.
    string unclassifiedFile = getDio()->read();
    if (unclassifiedFile == "fail") {
        getDio()->write("invalid input\n" + getMenu());
        return;
    }
    // Extracting each vector from the file to a vector of strings.
    vector<string> unclassifiedVector = this->dataProcessing.catchDelim(unclassifiedFile, '\n');
    // Extracting each cell in the line to a vector, and the vector to a vector.
    vector<vector<string>> unclassifiedLines = this->dataProcessing.createLinesArray(unclassifiedVector);
    // Creating a relative vector for the datastructures.
    vector<RelativeVector *> unclassifiedRelatives = creatUnclassifiedRelatives(unclassifiedLines);
    // Setting the relativeVectors to the database.
    this->getDatabase()->setUnclassifiedRelatives(unclassifiedRelatives);
    this->getDatabase()->setClassifiedRelatives(classifiedRelatives);
    // Approve to the client that the upload completed.
    getDio()->write("Upload complete.\n" + getMenu());
}

/**
 * Creating a RelativeVectors array from a vector of vector of lines.
 * @param lines The vector of vector of lines.
 * @return An array of Classified relative vectors.
 */
vector<RelativeVector *> UploadFile::creatUnclassifiedRelatives(vector<vector<string>> lines) {
    // Converting the cells to doubles.
    vector<vector<double>> doublesVec;
    this->dataProcessing.linesToDoubles(std::move(lines), doublesVec);
    // Creating the RelativeVector array.
    return this->dataProcessing.doublesUnclassifiedRelatives(doublesVec);
}

/**
 * Creating a Classified RelativeVectors from a vector of vector of lines.
 * @param lines The vector of vector of lines.
 * @return An array of Classified relative vectors.
 */
vector<ClassifiedRelativeVector *> UploadFile::creatClassifiedRelatives(vector<vector<string>> lines) {
    // Declaring a vector to store the classifications.
    vector<string> classifications;
    // extracting the classifications.
    extractClassifications(lines, classifications);
    // Init vector.
    vector<vector<double>> doublesVec;
    // Converting the cells to doubles.
    this->dataProcessing.linesToDoubles(lines, doublesVec);
    // Creating the ClassifiedRelativeVector array.
    return this->dataProcessing.doubleToClassifiedRelatives(doublesVec, classifications);
}

/**
 * Extracting the classifications from a vector of vectors.
 * @param lines The vector of all line vectors.
 * @param classifications The classifications vector to store the results.
 */
void UploadFile::extractClassifications(vector<vector<string>> &lines, vector<string> &classifications) {
    // Saving the size of the vector.
    unsigned int size = lines.size();
    // Saving all classifications.
    for (int i = 0; i < size; ++i) {
        classifications.push_back(lines[i].back());
        // Removing the classification for the original vector.
        lines[i].pop_back();
    }
}
