#ifndef EX4_RELATIVEDATABASE_H
#define EX4_RELATIVEDATABASE_H

#include "ClassifiedRelativeVector.h"
#include <utility>

class RelativeDatabase {
public:
    // Destructor for RelativeDatabase class.
    ~RelativeDatabase();

    RelativeDatabase(const RelativeDatabase &obj) = delete;

    static RelativeDatabase *getInstance();

    vector<RelativeVector *> getUnclassifiedRelatives();

    vector<ClassifiedRelativeVector *> getClassifiedRelatives();

    void setUnclassifiedRelatives(vector<RelativeVector *> unclassifiedRelativesVec);

    void setClassifiedRelatives(vector<ClassifiedRelativeVector *> classifiedRelativesVec);

    void setKElement(int k);

    void setMetric(string metric);

    int getKElement();

    string getMetric();

private:

    static RelativeDatabase *relativeDatabasePtr;

    int kElement = 5;

    string distanceMetric = "AUC";

    RelativeDatabase();

    vector<ClassifiedRelativeVector *> classifiedRelatives;
    vector<RelativeVector *> unclassifiedRelatives;
};

#endif //EX4_RELATIVEDATABASE_H
