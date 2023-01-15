#include "StandardIO.h"

StandardIO::StandardIO() = default;

StandardIO::~StandardIO() = default;


string StandardIO::read() {
    string line;
    getline(cin, line, '$');

    line += '\0';
    return line;
}

void StandardIO::write(string content) {
    cout << content;
}
