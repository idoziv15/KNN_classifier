#include "KnnAlgorithm.h"

/**
 * A constructor for this class, receiving a metric calculation and a number K for the Knn calculation.
 * @param calculation
 * @param kNum
 */
KnnAlgorithm::KnnAlgorithm(AbstractDistance *calculation, unsigned long kNum) {
    setCalc(calculation);
    setKNeighbors(kNum);
}

/**
 *  A default destructor.
 */
KnnAlgorithm::~KnnAlgorithm() = default;

/**
 * A setter for the K element.
 * @param kNum
 */
void KnnAlgorithm::setKNeighbors(unsigned long kNum) {
    this->kNeighbors = kNum;
}

/**
 * A setter for the calculation metric.
 * @param calculation
 */
void KnnAlgorithm::setCalc(AbstractDistance *calculation) {
    this->calc = calculation;
}

/**
 * A getter for the K element.
 * @return The K element.
 */
unsigned long KnnAlgorithm::getKNeighbors() {
    return this->kNeighbors;
}

/**
 * A getter for the metric calculation.
 * @return The metric calculation.
 */
AbstractDistance *KnnAlgorithm::getCalc() {
    return this->calc;
}


