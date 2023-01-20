
#ifndef EX4_CLASSIFYDATA_H
#define EX4_CLASSIFYDATA_H

#include "Commander.h"
#include "../DataAndAssistance/KnnAlgorithm.h"
#include "../Distances/AbstractDistance.h"
#include "../Distances/Euclidean.h"
#include "../Distances/Taxicab.h"
#include "../Distances/Chebyshev.h"
#include "../Distances/Canberra.h"
#include "../Distances/Minkowski.h"

/**
 * Given two files, creating a classification for each vector in the unclassified file.
 */
class ClassifyData : public Commander {
public:
    // A constructor for classify data class.
    ClassifyData(string description, AbstractDefaultIO *newDescription);
    // A destructor for classify data class.
    ~ClassifyData();
    // Classify the user data using knn algorithm.
    void execute() override;
    // Creating a new metric for the knn algorithm.
    AbstractDistance *distanceCreator(const string &distanceSpec);
};


#endif //EX4_CLASSIFYDATA_H
