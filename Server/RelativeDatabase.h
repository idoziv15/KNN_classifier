#ifndef EX4_RELATIVEDATABASE_H
#define EX4_RELATIVEDATABASE_H

#include "ClassifiedRelativeVector.h"
#include <utility>

class RelativeDatabase {
public:
    ~RelativeDatabase();

    RelativeDatabase(const RelativeDatabase &obj) = delete;

    static RelativeDatabase *getInstance();

    vector<RelativeVector *> getUnclassifiedRelatives();

    vector<ClassifiedRelativeVector *> getClassifiedRelatives();

    void setUnclassifiedRelatives(vector<RelativeVector *> unclassifiedRelativesVec);

    void setClassifiedRelatives(vector<ClassifiedRelativeVector *> classifiedRelativesVec);

private:

    static RelativeDatabase *relativeDatabasePtr;

    RelativeDatabase();

    vector<ClassifiedRelativeVector *> classifiedRelatives;
    vector<RelativeVector *> unclassifiedRelatives;
};

#endif //EX4_RELATIVEDATABASE_H
