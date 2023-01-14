#ifndef EX4_KNNALGORITHM_H
#define EX4_KNNALGORITHM_H

#include "Server/Distances/AbstractDistance.h"

class KnnAlgorithm {
public:
    KnnAlgorithm(AbstractDistance *calculation, unsigned long kNum);

    void setKNeighbors(unsigned long kNum);

    void setCalc(AbstractDistance *calculation);

    unsigned long getKNeighbors();

    AbstractDistance *getCalc();

    ~KnnAlgorithm();

private:
    // The calculation for the distance.
    AbstractDistance *calc;
    // The K nearest neighbors.
    unsigned long kNeighbors;
};

#endif //EX4_KNNALGORITHM_H
