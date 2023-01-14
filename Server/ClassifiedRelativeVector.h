
#ifndef EX4_CLASSIFIEDRELATIVEVECTOR_H
#define EX4_CLASSIFIEDRELATIVEVECTOR_H

#include "RelativeVector.h"
#include <utility>

class ClassifiedRelativeVector : public RelativeVector {
    ClassifiedRelativeVector(vector<double> valuesVec, string classification);

    ClassifiedRelativeVector(vector<double> valuesVec, string classification, double distance);

    ~ClassifiedRelativeVector();

    void setClassification(string classification);

    string getClassification();

    void setDistanceFromMasterVec(double distance);

    double getDistanceFromMasterVec();

private:
    // The classification of the vector.
    string classification;
    // The distance from the unclassified vector.
    double DistanceFromMasterVec{};
};

#endif //EX4_CLASSIFIEDRELATIVEVECTOR_H
