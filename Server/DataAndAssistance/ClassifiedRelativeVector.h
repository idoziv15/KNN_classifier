#ifndef EX4_CLASSIFIEDRELATIVEVECTOR_H
#define EX4_CLASSIFIEDRELATIVEVECTOR_H

#include "RelativeVector.h"
#include <utility>

/**
 * A class to represent a classified vector and his distance from a relevant vector.
 */
class ClassifiedRelativeVector : public RelativeVector {
public:
    // A constructor for the class who gets a values vector and classification.
    ClassifiedRelativeVector(vector<double> valuesVec, string classification);

    // A constructor for the class who gets a values vector, classification and distance from a relevant vector.
    ClassifiedRelativeVector(vector<double> valuesVec, string classification, double distance);

    // A default destructor for the class.
    ~ClassifiedRelativeVector();

    // A setter for the classification.
    void setClassification(string classification);

    // A getter for the classification.
    string getClassification();

    // A setter for the distance from a relevant vector.
    void setDistanceFromMasterVec(double distance);

    // A getter for the distance from a relevant vector.
    double getDistanceFromMasterVec();

private:
    // The classification of the vector.
    string classification;
    // The distance from the unclassified vector.
    double DistanceFromMasterVec{};
};

#endif //EX4_CLASSIFIEDRELATIVEVECTOR_H
