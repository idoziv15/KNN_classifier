#include "StandardIO.h"

StandardIO::StandardIO() = default;

StandardIO::~StandardIO() = default;


string StandardIO::read() {
    return "Read this file!";
}

void StandardIO::write(const string& content) {
    cout << "Wrote to this file! the content is:" << content << endl;
}
