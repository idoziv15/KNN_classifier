#include "SendToDownload.h"

/**
 * The constructor of sentTODownload class.
 * @param description The class description.
 * @param Dio The default IO.
 * @param database The general database.
 */
SendToDownload::SendToDownload(string description, AbstractDefaultIO *Dio, RelativeDatabase* database)
        : Commander(std::move(description), Dio, database) {

}

/**
 * Sending the result of the calc if exist, otherwise send an error massage.
 */
void SendToDownload::execute() {
    // Checking if the user upload data.
    if (getDatabase()->getClassifiedRelatives().empty() || getDatabase()->getUnclassifiedRelatives().empty()) {
        getDio()->write("fail");
        getDio()->read();
        getDio()->write("please upload data\n" + getMenu());
        return;
    }
    // Checking if the user chose to classify the unclassified data.
    if (getDatabase()->getResult().empty()) {
        getDio()->write("fail");
        getDio()->read();
        getDio()->write("please classify the data\n" + getMenu());
        return;
    }

    // The output is the full file of vectors which been classified.
    string output;
    // Get the size of the result vector.
    unsigned int size = getDatabase()->getResult().size();
    // Concatenating the file.
    for (int i = 0; i < size; ++i) {
        output += getDatabase()->getResult()[i];
    }
    getDio()->write(output);
    getDio()->read();
    getDio()->write(getMenu());
}
