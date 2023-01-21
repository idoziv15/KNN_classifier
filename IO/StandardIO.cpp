#include "StandardIO.h"

StandardIO::StandardIO() = default;

StandardIO::~StandardIO() = default;


string StandardIO::read() {
    string line, temp;
    getline(cin, line, '$');
    getline(cin, temp, '\n');
//    line += "\n";
    return line;
}

void StandardIO::write(string content) {

    cout << content;
}
