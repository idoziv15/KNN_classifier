#include "StandardIO.h"

/**
 * A default constructor.
 */
StandardIO::StandardIO() = default;

/**
 * A default destructor.
 */
StandardIO::~StandardIO() = default;

/**
 * An implementation of read as an IO class.
 * @return The string received from the user.
 */
string StandardIO::read() {
    // Creating string to store the user's requests.
    string line, temp;
    // Getting the user's input until he presses '$'.
    getline(cin, line, '$');
    // Clearing the buffer.
    getline(cin, temp, '\n');
    // Returning the result.
    return line;
}

/**
 * An implementation for the write as an IO class.
 * @param content The content the user wants to write.
 */
void StandardIO::write(string content) {
    // As standard Io, just print the content to the screen.
    cout << content;
}
