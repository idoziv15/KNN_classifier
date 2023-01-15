#include "EndConnection.h"

#include <utility>

EndConnection::EndConnection(string description, AbstractDefaultIO *Dio)
        : Commander(std::move(description), Dio) {

}


/**
 * Free all data about the process.
 */
void EndConnection::execute() {
    // Calling the delete method from database class to free all the unclassified data that saved for this client.
    getDatabase()->deleteUnclassified();
    // Calling the delete method from database class to free all the classified data that saved for this client.
    getDatabase()->deleteClassified();
    // Delete the database instance.
    delete getDatabase();
}
