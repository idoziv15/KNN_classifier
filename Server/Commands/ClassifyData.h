
#ifndef EX4_CLASSIFYDATA_H
#define EX4_CLASSIFYDATA_H
#include "Commander.h"
class ClassifyData : public Commander {
public:
    ClassifyData(string description, AbstractDefaultIO *newDescription);
    ~ClassifyData();
    void execute() override;

};


#endif //EX4_CLASSIFYDATA_H
