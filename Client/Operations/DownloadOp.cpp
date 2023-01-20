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


    //  download the file with threads.!!!!!!!!!!!!!!!! HERE!!!!!!!!!!!!!!

}

/**
 * Downloading the file to the computer of the client.
 * @param file The file as a string to download.
 */
void DownloadOp::downloadFileToComputer(string file) {

}
