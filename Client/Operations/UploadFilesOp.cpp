#include "UploadFilesOp.h"

/**
 * Uploading two files to the server.
 */
void UploadFilesOp::executeOp() {
    if (!createSendFile()) {
        return;
    }
    if (!createSendFile()) {
        getDio()->write("invalid$");
    }
}

/**
 * Creating a string from a file content and sending it to the server.
 * If the path to the file is invalid, print "invalid input" and return.
 * @return a boolen answer if the operation succeeded or not.
 */
bool UploadFilesOp::createSendFile() {
    string firstFilePath = userInput();
    if (!clientValidations.validPath(firstFilePath)) {
        cout << "invalid input" << endl;
        return false;
    }
    string firstFile = uploadFile(firstFilePath);
    firstFile += "$";
    getDio()->write(firstFile);
    string response = getDio()->read();
    cout << response << endl;
    return true;
}

/**
 * Getting a full file and concatenating it to a string.
 * @param path The path to the file.
 * @return The file as a string.
 */
string UploadFilesOp::uploadFile(string path) {
    // Create a new stream to read from the file.
    fstream myFile;
    // Open the file.
    myFile.open(path);
    // Create a String to read a full line from the file.
    string fullVector, fullFile;
    // Read until you reached EOF.
    while (myFile.good()) {
        // Get the line from the file and put it in the fullVector.
        getline(myFile, fullVector);
        // Check if we detected an empty line and ignore it.
        if (fullVector.empty()) {
            continue;
        }
        fullFile += fullVector;
    }
    return fullFile;
}