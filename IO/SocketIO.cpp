#include "SocketIO.h"

/**
 * A constructor receives a new socketId.
 * @param newSocket The new socket.
 */
SocketIO::SocketIO(int newSocket) {
    setSocket(newSocket);
}

/**
 * A default destructor.
 */
SocketIO::~SocketIO() = default;

/**
 * A getter for the socket id.
 * @return The int representing the socket id.
 */
int SocketIO::getSocket() {
    return this->socketID;
}


/**
 * A setter for the socket id.
 * @param socket The new socket id.
 */
void SocketIO::setSocket(int socket) {
    this->socketID = socket;
}

/**
 * An implementation for the write function as an IO.
 * @param content The content of the sending message.
 */
void SocketIO::write(string content) {
    // Concertinaing the string to use "TA Protocol"
    content += "$\0";
    // Getting the message length.
    unsigned long lenMsg = content.size();
    // Write the content to the buffer ready to send.
    const char *buffer = content.c_str();
    long sent_bytes = send(getSocket(), buffer, lenMsg, 0);
    // Checking if sent successfully.
    if (sent_bytes < 0) {
        perror("error sending to client");
        exit(0);
    }
}

/**
 * An implementation for the read function as an IO.
 * @return The message received.
 */
string SocketIO::read() {
    // Creating the result string.
    string response;
    // Creating the buffer for the message.
    char buffer[4096];
    // receiving the data until the token is reached.
    while (true) {
        // Get the data.
        long readBytes = recv(getSocket(), buffer, 4096, 0);
        // Check if the "receive" method worked.
        if (readBytes < 0) {
            // If it didn't work, raise an error.
            perror("Error receiving data.");
            exit(0);
        }
        for (int i = 0; i < readBytes; ++i) {
            response += buffer[i];
        }
        // If the token is reached, finish reading.
        if (response.back() == '$') {
            // Remove the token.
            response.pop_back();
            // Return the response.
            return response;
        }
    }
}