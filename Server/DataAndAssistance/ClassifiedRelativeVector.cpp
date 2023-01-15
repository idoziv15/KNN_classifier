#include "ClassifiedRelativeVector.h"

/**
 * A Constructor for the class, receiving a vector of doubles.
 * @param initValuesVector The initiated vector of the class.
 */
ClassifiedRelativeVector::ClassifiedRelativeVector(vector<double> valuesVec, string classification)
        : RelativeVector(std::move(valuesVec)) {
    setClassification(std::move(classification));
}

/**
 * A constructor for the class.
 * @param valuesVec The values vector of doubles storing the data of the vector.
 * @param classification The classification of the vector.
 * @param distance The distance from a relevant vector.
 */
ClassifiedRelativeVector::ClassifiedRelativeVector(vector<double> valuesVec, string classification, double distance)
        : RelativeVector(std::move(valuesVec)) {
    // Set the classification of the vector.
    setClassification(std::move(classification));
    // Set the distance from a relevant vector.
    setDistanceFromMasterVec(distance);
}

/**
 * A default destructor for the class.
 */
ClassifiedRelativeVector::~ClassifiedRelativeVector() = default;

/**
 * A setter for the classification of the vector.
 * @param newClassification The classification string.
 */
void ClassifiedRelativeVector::setClassification(string newClassification) {
    this->classification = std::move(newClassification);
}

/**
 * A getter for the classification of the vector.
 * @return The classification string.
 */
string ClassifiedRelativeVector::getClassification() {
    return this->classification;
}

/**
 * A setter fir the distance from a relevant vector.
 * @param distance the distance as a double.
 */
void ClassifiedRelativeVector::setDistanceFromMasterVec(double distance) {
    this->DistanceFromMasterVec = distance;
}

/**
 * A getter for the distance from a relevant vector.
 * @return The distance as a double.
 */
double ClassifiedRelativeVector::getDistanceFromMasterVec() {
    return this->DistanceFromMasterVec;
}



