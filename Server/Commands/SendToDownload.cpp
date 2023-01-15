
#include "SendToDownload.h"

void SendToDownload::execute() {
    if (getDatabase()->getClassifiedRelatives().empty() || getDatabase()->getUnclassifiedRelatives().empty()) {
        getDio()->write("please upload data\n");
        return;
    }
    if (getDatabase()->getResult().empty()) {
        getDio()->write("please classify the data\n");
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
}
