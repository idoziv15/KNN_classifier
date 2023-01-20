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
    if(response == "fail"){
        getDio()->write("OK");
        return;
    }

    //  download the file with threads.!!!!!!!!!!!!!!!! HERE!!!!!!!!!!!!!!

}

void DownloadOp::downloadFileToComputer() {

}
