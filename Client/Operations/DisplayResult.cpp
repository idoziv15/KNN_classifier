#include "DisplayResult.h"

DisplayResult::DisplayResult(AbstractDefaultIO *defaultIo) : AbstractOperations(defaultIo) {

}

DisplayResult::~DisplayResult() = default;

void DisplayResult::executeOp() {
    string classifiedData, tempLine;
//    istringstream tempData (getDio()->read());
//    getline(tempData,tempLine);
//    classifiedData += tempLine + "\n";
//    while (tempLine != "$"){
//        getline(tempData,tempLine);
//        classifiedData += tempLine + "\n";
//    }
    classifiedData = getDio()->read();
    cout << classifiedData << ends;
}
