#ifndef EX4_CLIENTMANAGEMENT_H
#define EX4_CLIENTMANAGEMENT_H

#include <IO/AbstractDefaultIO.h>
#include <cstdlib>


using namespace std;

/**
 * This class is responsible to manage all data and flow regard to the client.
 */
class ClientManagement {
public:

    // A constructor for the class.
    ClientManagement();

    // A constructor which receives a default io pointer.
    ClientManagement(AbstractDefaultIO* dio);

    // A destructor for the class.
    ~ClientManagement();

    void start();


    // A setter for the default io.
    void setDefaultIO(AbstractDefaultIO *dio);

    // A getter for the default io.
    AbstractDefaultIO *getDefaultIO();

private:
    // IO member.
    AbstractDefaultIO *defaultIo{};
};

#endif //EX4_CLIENTMANAGEMENT_H
