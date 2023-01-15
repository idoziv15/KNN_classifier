#include "StandardIO.h"

StandardIO::StandardIO() = default;

StandardIO::~StandardIO() = default;


string StandardIO::read() {
    string line;
    getline(cin, line, '$');

    return line;
}

void StandardIO::write(string content) {
    cout << content;
}
