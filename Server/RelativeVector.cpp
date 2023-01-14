
#include "RelativeVector.h"

/**
 * A Constructor for the class, receiving a vector of doubles.
 * @param initValuesVector The initiated vector of the class.
 */
RelativeVector::RelativeVector(vector<double> initValuesVector) {
    setValuesVector(std::move(initValuesVector));
}

/**
 * A default constructor.
 */
RelativeVector::RelativeVector() = default;

/**
 * A default destructor.
 */
RelativeVector::~RelativeVector() = default;

/**
 * A Setter for the values vector.
 * @param newValuesVector
 */
void RelativeVector::setValuesVector(vector<double> newValuesVector) {
    this->valuesVector = std::move(newValuesVector);
}

/**
 * A getter for the values vector.
 * @return The values vector.
 */
vector<double> RelativeVector::getValuesVector() {
    return this->valuesVector;
}
