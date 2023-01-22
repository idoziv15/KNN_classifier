#ifndef EX4_SOCKETIO_H
#define EX4_SOCKETIO_H

#include "AbstractDefaultIO.h"
#include <sys/socket.h>

/**
 * This class read and write using socket.
 */
class SocketIO : public AbstractDefaultIO {
public:

    // A constructor for SocketIO class.
    explicit SocketIO(int newSocket);

    // A default destructor for SocketIo class.
    ~SocketIO();

    // Read method used to read a message from the socket.
    string read() override;

    // Write method is used to write throw the socket.
    void write(string content) override;

    // Setter for the socket member of this class.
    void setSocket(int socket);

    // Getter for the socket member of this class.
    int getSocket();


private:
    //The socketID for read and write purpose.
    int socketID;
};

#endif //EX4_SOCKETIO_H
