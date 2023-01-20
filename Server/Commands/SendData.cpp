#include "SendData.h"

#include <utility>

SendData::SendData(string description, AbstractDefaultIO *Dio)
        : Commander(std::move(description), Dio) {

}


/**
 * Sending the result of the calc if exist, otherwise send an error massage.
 */
void SendData::execute() {
    // Checking if the user upload data.
    if (getDatabase()->getClassifiedRelatives().empty() || getDatabase()->getUnclassifiedRelatives().empty()) {
        getDio()->write("please upload data\n" + getMenu());
        return;
    }
    // Checking if the user choose to classify the data.
    if (getDatabase()->getResult().empty()) {
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
    // Concatenating done to the end of the string.
    output += "Done\n";
    getDio()->write(output + getMenu());
}
