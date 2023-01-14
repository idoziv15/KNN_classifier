//
// Created by tal on 1/14/23.
//

#ifndef EX4_COMMANDER_H
#define EX4_COMMANDER_H

#include "AbstractDefaultIO.h"

class Commander {
public:
    Commander();

    // ADD Database!!
    Commander(string description, AbstractDefaultIO *newDescription);

    ~Commander();

    virtual void execute() = 0;

    void setDescription(string description);

    string getDescription();

    void setDio(AbstractDefaultIO *newDio);

    AbstractDefaultIO *getDio();

    // Setter and getter for database.


private:
    string description;
    AbstractDefaultIO *dio = nullptr;
    // Database!!!!
};

#endif //EX4_COMMANDER_H
