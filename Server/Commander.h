//
// Created by tal on 1/14/23.
//

#ifndef EX4_COMMANDER_H
#define EX4_COMMANDER_H

#include "AbstractDefaultIO.h"
#include "RelativeDatabase.h"

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

    RelativeDatabase * getDatabase();




private:
    string description;
    AbstractDefaultIO *dio = nullptr;
    RelativeDatabase *relativeDatabase;
    // Database!!!!
};

#endif //EX4_COMMANDER_H
