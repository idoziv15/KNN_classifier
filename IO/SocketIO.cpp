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

}

/**
 * An implementation for the read function as an IO.
 * @return The message received.
 */
string SocketIO::read() {

}