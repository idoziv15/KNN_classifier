#include "ClassifiedRelativeVector.h"

#include <utility>

/**
 * A Constructor for the class, receiving a vector of doubles.
 * @param initValuesVector The initiated vector of the class.
 */
ClassifiedRelativeVector::ClassifiedRelativeVector(vector<double> valuesVec, string classification)
        : RelativeVector(std::move(valuesVec)) {
    setClassification(std::move(classification));
}

ClassifiedRelativeVector::ClassifiedRelativeVector(vector<double> valuesVec, string classification, double distance)
        : RelativeVector(std::move(valuesVec)) {
    setClassification(std::move(classification));
    setDistanceFromMasterVec(distance);
}

ClassifiedRelativeVector::~ClassifiedRelativeVector() = default;

void ClassifiedRelativeVector::setClassification(string newClassification) {
    this->classification = std::move(newClassification);
}

string ClassifiedRelativeVector::getClassification() {
    return this->classification;
}

void ClassifiedRelativeVector::setDistanceFromMasterVec(double distance) {
    this->DistanceFromMasterVec = distance;
}

double ClassifiedRelativeVector::getDistanceFromMasterVec() {
    return this->DistanceFromMasterVec;
}



