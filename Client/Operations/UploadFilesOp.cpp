#include "UploadFilesOp.h"

/**
 * Uploading two files to the server.
 */
void UploadFilesOp::executeOp() {
    if (!createSendFileOne()) {
        return;
    }
    // Read the server's response.
    string response = getDio()->read();
    cout << response << endl;
    createSendFileTwo();
}

/**
 * Creating a string from a file content and sending it to the server.
 * If the path to the file is invalid, print "invalid input" and return.
 * @return a boolean answer if the operation succeeded or not.
 */
bool UploadFilesOp::createSendFileOne() {
    // Reading the server's: "Please upload your local train CSV file.\n"
    cout << getDio()->read();
    // Get the path to the first file.
    string firstFilePath = userInput();
    // Checking if the file is ok to read.
    if (!clientValidations.validPath(firstFilePath)) {
        // Tell the server an error accord.
        getDio()->write("fail");
        return false;
    }
    // Get the content of the file.
    string firstFile = uploadFile(firstFilePath);
    // Send the file to the server.
    getDio()->write(firstFile);
    return true;
}

/**
 * Creating a string from a file content and sending it to the server.
 * If the path to the file is invalid, print "invalid input" and return.
 * @return a boolean answer if the operation succeeded or not.
 */
bool UploadFilesOp::createSendFileTwo() {
    // Get the path to the first file.
    string firstFilePath = userInput();
    // Checking if the file is ok to read.
    if (!clientValidations.validPath(firstFilePath)) {
        // Tell the server an error accord.
        getDio()->write("fail");
        return false;
    }
    // Get the content of the file.
    string firstFile = uploadFile(firstFilePath);
    // Send the file to the server.
    getDio()->write(firstFile);
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
        fullFile += fullVector + "\n";
    }
    return fullFile;
}

