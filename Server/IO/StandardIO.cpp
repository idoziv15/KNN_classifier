#include "StandardIO.h"

StandardIO::StandardIO() = default;

StandardIO::~StandardIO() = default;


string StandardIO::read() {
    fflush(stdin);
    string line;
    getline(cin, line, '$');
    string line2 = line;

    line2 += '\0';
    return line2;

}

void StandardIO::write(string content) {
    cout << content;
}
