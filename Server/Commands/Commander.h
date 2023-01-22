#ifndef EX4_COMMANDER_H
#define EX4_COMMANDER_H

#include <utility>
#include "../../IO/AbstractDefaultIO.h"
#include "../DataAndAssistance/RelativeDatabase.h"
#include "../DataAndAssistance/ServerValidations.h"
#include "../DataAndAssistance/DataProcessing.h"

/**
 *  An abstract class - Gathers all the options the user can choice (command).
 */
class Commander {
public:
    // A default constructor for commander class.
    Commander();

    // Constructor for commander class.
    Commander(string description, AbstractDefaultIO *defaultIo, RelativeDatabase *relativeDatabase);

    // Destructor for commander class.
    ~Commander();

    // Pure virtual function that all the implementing classes(commands) need to have.
    virtual void execute() = 0;

    // A setter for description member.
    void setDescription(string description);

    // A getter for description member.
    string getDescription();

    // A setter for IO member.
    void setDio(AbstractDefaultIO *newDio);

    // A getter fot IO member.
    AbstractDefaultIO *getDio();

    // A getter for relative-database member.
    RelativeDatabase *getDatabase();

    // A setter for the menu.
    void setMenu(string menu);

    // Setter for database member.
    void setDatabase(RelativeDatabase *database);

    // A getter for the menu.
    string getMenu();


protected:
    // Member for data processing that all the inheritance can use.
    DataProcessing dataProcessing;
    // Member for validation that all the inheritance can use.
    ServerValidations serverValidations;
    // The full menu.
    string fullMenu;


private:
    // The specific description for each inheritance.
    string description;
    // The IO member.
    AbstractDefaultIO *dio = nullptr;
    // The database member.
    RelativeDatabase *relativeDatabase;
};

#endif //EX4_COMMANDER_H
