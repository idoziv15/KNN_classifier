#include "Commander.h"

#include <utility>

/**
 * A default constructor.
 */
Commander::Commander() {
    this->relativeDatabase = RelativeDatabase::getInstance();
}

/**
 * A default destructor.
 */
Commander::~Commander() = default;

/**
 * A constructor who receives a description and a pointer to AbstractDefaultIo object.
 * @param description The description of the command.
 * @param dio The IO tool the command is using.
 */
Commander::Commander(string description, AbstractDefaultIO *dio) {
    setDescription(std::move(description));
    setDio(dio);
    this->relativeDatabase = RelativeDatabase::getInstance();
}

/**
 * A setter for the description.
 * @param newDescription
 */
void Commander::setDescription(string newDescription) {
    this->description = std::move(newDescription);
}

/**
 * A getter for the description.
 * @return the description.
 */
string Commander::getDescription() {
    return this->description;
}

/**
 * A setter for the Dio polymorphic member.
 * @param newDio The io tool.
 */
void Commander::setDio(AbstractDefaultIO *newDio) {
    this->dio = newDio;
}

/**
 * A setter for the polymorphic member.
 * @return The new io tool.
 */
AbstractDefaultIO *Commander::getDio() {
    return dio;
}

/**
 * A getter for the database;
 * @return The database.
 */
RelativeDatabase *Commander::getDatabase() {
    return this->relativeDatabase;
}
