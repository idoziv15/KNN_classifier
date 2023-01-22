#include "DownloadOp.h"

/**
 * A default destructor for DownloadOp class.
 */
DownloadOp::~DownloadOp() = default;

/**
 * A constructor for DownloadOp class.
 * @param defaultIo socketIO.
 */
DownloadOp::DownloadOp(AbstractDefaultIO *defaultIo) : AbstractOperations(defaultIo) {
}

/**
 * Downloading the file to the computer of the client.
 * @param file The file as a string to download.
 */
void *downloadFileToComputer(string file, string path) {
    // Create a file stream.
    std::ofstream myFile;
    // Open the file to the path we gor from the user.
    myFile.open(path);
    // Check if the path is valid.
    if (!myFile) {
        cout << "invalid input" << endl;
        return nullptr;
    }
    // Write to the file.
    myFile << file;
    // Close the file.
    myFile.close();
    return nullptr;
}

/**
 * Implementing the operation by downloading the result file from the server to the computer.
 */
void DownloadOp::executeOp() {
    string response = getDio()->read();
    if (response == "fail") {
        getDio()->write("OK");
        return;
    }
    // Confirmation the
    getDio()->write("OK");
    // Get the path from the user.
    string path = userInput();
    // Creating a thread to download the file.
    thread t2(downloadFileToComputer, response, path);
    // Detaching the thread from the main thread.
    t2.detach();
}


