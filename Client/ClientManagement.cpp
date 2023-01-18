#include "ClientManagement.h"

/**
 * A default constructor.
 */
ClientManagement::ClientManagement() = default;

/**
 * A default destructor.
 */
ClientManagement::~ClientManagement() = default;


/**
 * A getter for the DIO.
 * @return The DIO pointer of type AbstractDefaultIO.
 */
AbstractDefaultIO *ClientManagement::getDefaultIO() {
    return this->defaultIo;
}

/**
 * A setter for the default io.
 * @param dio The dio member of the class.
 */
void ClientManagement::setDefaultIO(AbstractDefaultIO *dio) {
    this->defaultIo = dio;
}

/**
 * A constructor who receives a default io pointer.
 * @param dio The default io pointer.
 */
ClientManagement::ClientManagement(AbstractDefaultIO *dio) {
    setDefaultIO(dio);
}

/**
 * This method starts the client's operation with the server.
 */
void ClientManagement::start() {
//    while(true){
//        string response = getDefaultIO()->read();
//
//    }
}
