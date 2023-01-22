#include "Commander.h"

/**
 * A default destructor.
 */
Commander::~Commander() = default;

/**
 * A constructor who receives a description and a pointer to AbstractDefaultIo object.
 * @param description The description of the command.
 * @param defaultIo The IO tool the command is using.
 * @param database The general database.
 */
Commander::Commander(string description, AbstractDefaultIO *defaultIo, RelativeDatabase* database) {
    setDatabase(database);
    setDescription(std::move(description));
    setDio(defaultIo);
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
    return this->dio;
}

/**
 * A getter for the database;
 * @return The database.
 */
RelativeDatabase *Commander::getDatabase() {
    return this->relativeDatabase;
}

/**
 * A setter for the menu.
 * @param menu The menu string.
 */
void Commander::setMenu(string menu) {
    this->fullMenu = std::move(menu);
}

/**
 * A getter for the full menu.
 * @return The full menu.
 */
string Commander::getMenu() {
    return this->fullMenu;
}
/**
 * Setter for the database member.
 * @param database a reference to a database.
 */
void Commander::setDatabase(RelativeDatabase *database) {
    this->relativeDatabase = database;
}
