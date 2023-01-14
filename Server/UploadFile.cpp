#include "UploadFile.h"


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

    // Reading a file of unclassified vectors.
    string unclassifiedFile = getDio()->read();
    // Extracting each vector from the file to a vector of strings.
    vector<string> unclassifiedVector = this->dataProcessing.catchDelim(unclassifiedFile, '\n');
    // Extracting each cell in the line to a vector, and the vector to a vector.
    vector<vector<string>> unclassifiedLines = this->dataProcessing.createLinesArray(unclassifiedVector);
    // Creating a relative vector for the datastructures.
    vector<RelativeVector *> unclassifiedRelatives = creatUnclassifiedRelatives(unclassifiedLines);

    // Reading a file of classified vectors.
    string classifiedFile = getDio()->read();
    // Extracting each vector from the file to a vector of strings.
    vector<string> classifiedVector = this->dataProcessing.catchDelim(classifiedFile, '\n');
    // Extracting each cell in the line to a vector, and the vector to a vector.
    vector<vector<string>> classifiedLines = this->dataProcessing.createLinesArray(classifiedVector);
    // Creating a relative vector for the datastructures.
    vector<ClassifiedRelativeVector *> classifiedRelatives = creatClassifiedRelatives(classifiedLines);

    // Setting the relativeVectors to the database.
    this->getDatabase()->setUnclassifiedRelatives(unclassifiedRelatives);
    this->getDatabase()->setClassifiedRelatives(classifiedRelatives);
}

/**
 * Creating a RelativeVectors array from a vector of vector of lines.
 * @param lines The vector of vector of lines.
 * @return An array of Classified relative vectors.
 */
vector<RelativeVector *> UploadFile::creatUnclassifiedRelatives(vector<vector<string>> lines) {
    // Converting the cells to doubles.
    vector<vector<double>> doublesVec = this->dataProcessing.linesToDoubles(lines);
    // Creating the RelativeVector array.
    return this->dataProcessing.doublesUnclassifiedRelatives(doublesVec);
}

/**
 * Creating a Classified RelativeVectors from a vector of vector of lines.
 * @param lines The vector of vector of lines.
 * @return An array of Classified relative vectors.
 */
vector<ClassifiedRelativeVector *> UploadFile::creatClassifiedRelatives(vector<vector<string>> lines) {
    // Saving the size of the vector.
    unsigned int size = lines.size();
    // Initiating a new classification vector to store the classifications.
    vector<string> classifications;
    // Saving all classifications.
    for (int i = 0; i < size; ++i) {
        classifications[i] = lines[i].back();
        // Removing the classification for the original vector.
        lines[i].pop_back();
    }
    // Converting the cells to doubles.
    vector<vector<double>> doublesVec = this->dataProcessing.linesToDoubles(lines);
    // Creating the ClassifiedRelativeVector array.
    return this->dataProcessing.doubleToClassifiedRelatives(doublesVec, classifications);
}
