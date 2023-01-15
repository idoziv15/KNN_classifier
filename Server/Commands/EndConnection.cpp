#include "EndConnection.h"

/**
 * Free all data about the process.
 */
void EndConnection::execute() {
    getDatabase()->deleteUnclassified();
    getDatabase()->deleteClassified();
    delete getDatabase();
}
