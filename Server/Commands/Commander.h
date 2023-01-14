//
// Created by tal on 1/14/23.
//

#ifndef EX4_COMMANDER_H
#define EX4_COMMANDER_H

#include "Server/IO/AbstractDefaultIO.h"
#include "Server/DataAndAssistance/RelativeDatabase.h"
#include "Server/DataAndAssistance/ServerValidations.h"
#include "Server/DataAndAssistance/DataProcessing.h"

class Commander {
public:
    Commander();

    Commander(string description, AbstractDefaultIO *newDescription);

    ~Commander();

    virtual void execute() = 0;

    void setDescription(string description);

    string getDescription();

    void setDio(AbstractDefaultIO *newDio);

    AbstractDefaultIO *getDio();

    RelativeDatabase *getDatabase();


protected:
    DataProcessing dataProcessing;
    ServerValidations serverValidations;

private:
    string description;
    AbstractDefaultIO *dio = nullptr;
    RelativeDatabase *relativeDatabase;

};

#endif //EX4_COMMANDER_H
