#include "EndConnection.h"

/**
 * The constructor for EndConnection class.
 * @param description The description of the class.
 * @param Dio The default Io.
 * @param database The general database.
 */
EndConnection::EndConnection(string description, AbstractDefaultIO *Dio, RelativeDatabase *database)
        : Commander(std::move(description), Dio, database) {

}

/**
 * Free all data about the process.
 */
void EndConnection::execute() {
    // Calling the delete method from database class to free all the unclassified data that saved for this client.
    getDatabase()->deleteUnclassified();
    // Calling the delete method from database class to free all the classified data that saved for this client.
    getDatabase()->deleteClassified();
}
