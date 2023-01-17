#ifndef EX4_RELATIVEDATABASE_H
#define EX4_RELATIVEDATABASE_H

#include "ClassifiedRelativeVector.h"
#include <utility>
#include <bits/stdc++.h>

/**
 * A relative database class for a specific client.
 * Contains all data the client wants from the server and methods related to it.
 */
class RelativeDatabase {
public:
    // Destructor for RelativeDatabase class.
    ~RelativeDatabase();

    // Deleting the option of a copy constructor.
    RelativeDatabase(const RelativeDatabase &obj) = delete;

    // Getting the instance of the class as a singleton.
    static RelativeDatabase *getInstance();

    // A getter for the unclassified relative vector.
    vector<RelativeVector *> getUnclassifiedRelatives();

    // A getter for the classified relative vector.
    vector<ClassifiedRelativeVector *> getClassifiedRelatives();

    // A setter for the unclassified relative vector.
    void setUnclassifiedRelatives(vector<RelativeVector *> unclassifiedRelativesVec);

    // A setter for the classified relative vector.
    void setClassifiedRelatives(vector<ClassifiedRelativeVector *> classifiedRelativesVec);

    // A setter for the K element (for the Knn algorithm).
    void setKElement(unsigned long k);

    // A setter for the metric calculation.
    void setMetric(string metric);

    // A getter for the current K element.
    unsigned long getKElement();

    // A setter for the current metric calculation.
    string getMetric();

    // A setter for the result after the calculation.
    void setResultVec(vector<string> result);

    // A destroy function for the unclassified relative vectors.
    void deleteUnclassified();

    // A destroy function for the classified relative vectors.
    void deleteClassified();

    // A getter for the result after the calculation.
    vector<string> getResult();

private:
    // The constructor as a singleton.
    RelativeDatabase();
    // The pointer to the class to implement the singleton.
    static RelativeDatabase *relativeDatabasePtr;
    // The kElement set to a default value of 5.
    unsigned long kElement = 5;
    // The metric set to a default value of "AUC".
    string distanceMetric = "AUC";
    // Classified file.
    vector<ClassifiedRelativeVector *> classifiedRelatives;
    // Unclassified file.
    vector<RelativeVector *> unclassifiedRelatives;
    // After classification vector.
    vector<string> resultVec;
};

#endif //EX4_RELATIVEDATABASE_H
