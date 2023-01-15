#ifndef EX4_RELATIVEDATABASE_H
#define EX4_RELATIVEDATABASE_H

#include "ClassifiedRelativeVector.h"
#include <utility>
#include <bits/stdc++.h>

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

    void setKElement(unsigned long k);

    void setMetric(string metric);

    unsigned long getKElement();

    string getMetric();

    void setResultVec(vector<string> result);

    void deleteUnclassified();

    void deleteClassified();

    vector<string> getResult();

private:
    // The pointer to the class to implement the singleton.
    static RelativeDatabase *relativeDatabasePtr;
    // The kElement set to a default value of 5.
    unsigned long kElement = 5;
    // The metric set to a default value of "AUC".
    string distanceMetric = "AUC";

    // The constructor as a singleton.
    RelativeDatabase();

    // Classified file.
    vector<ClassifiedRelativeVector *> classifiedRelatives;
    // Unclassified file.
    vector<RelativeVector *> unclassifiedRelatives;
    // After classification vector.
    vector<string> resultVec;
};


#endif //EX4_RELATIVEDATABASE_H
