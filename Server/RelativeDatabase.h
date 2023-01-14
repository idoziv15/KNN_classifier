#ifndef EX4_RELATIVEDATABASE_H
#define EX4_RELATIVEDATABASE_H

#include "ClassifiedRelativeVector.h"
#include <utility>

class RelativeDatabase {

    RelativeDatabase();

    ~RelativeDatabase();

    vector<RelativeVector *> getUnclassifiedRelatives();

    vector<ClassifiedRelativeVector *> getClassifiedRelatives();

    void setUnclassifiedRelatives(vector<RelativeVector *> unclassifiedRelativesVec);

    void setClassifiedRelatives(vector<ClassifiedRelativeVector *> classifiedRelativesVec);

private:
    vector<ClassifiedRelativeVector *> classifiedRelatives;
    vector<RelativeVector *> unclassifiedRelatives;
};

#endif //EX4_RELATIVEDATABASE_H
