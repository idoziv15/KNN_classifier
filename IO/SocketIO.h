#ifndef EX4_SOCKETIO_H
#define EX4_SOCKETIO_H

#include "AbstractDefaultIO.h"

class SocketIO : public AbstractDefaultIO {
public:

    explicit SocketIO(int newSocket);

    ~SocketIO();

    string read() override;

    void write(string content) override;

    void setSocket(int socket);

    int getSocket();


private:
    int socketID;
};

#endif //EX4_SOCKETIO_H
