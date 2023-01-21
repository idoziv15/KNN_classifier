#ifndef EX4_KNNALGORITHM_H
#define EX4_KNNALGORITHM_H

#include "../Distances/AbstractDistance.h"
#include "ClassifiedRelativeVector.h"
#include <cstdlib>
#include <vector>
#include <string>
#include "RelativeVector.h"
#include "../Distances/AbstractDistance.h"
#include <bits/stdc++.h>
#include <utility>
#include <map>
#include <cmath>

/**
 * A class that calculates the K nearest neighbors from a relevant vector.
 * Can receive a full file or a single vector to calculate.
 */
class KnnAlgorithm {
public:
    // A constructor who receives a calculation metric and a number K.
    KnnAlgorithm(AbstractDistance *calculation, unsigned long kNum);

    // A default destructor.
    ~KnnAlgorithm();

    // A setter for the K element.
    void setKNeighbors(unsigned long kNum);

    // A setter for the claculation metric.
    void setCalc(AbstractDistance *calculation);

    // A getter for the K element.
    unsigned long getKNeighbors();

    // A getter for the calculation metric.
    AbstractDistance *getCalc();

    // A setter for the cataloged vectors (classified relative vectors).
    void setCatalogVec(vector<ClassifiedRelativeVector *> catalogVectors);

    // A getter for the cataloged vector.
    vector<ClassifiedRelativeVector *> getCataloged();

    // Given a vector, classifying it.
    string classifyVector(vector<double> unclassifiedVector);

    // Calculating the distance of the cataloged vectors from the given vector.
    bool calculateDistances(vector<double> uVec);

    // Sorting the vector by distances.
    vector<ClassifiedRelativeVector *> sortingAndGettingK();

    // Check validation of the vectors.
    bool sizeComparison(const vector<double> &v1, const vector<double> &v2);

    // Given two files, calculating the classification of the unclassified file.
    vector<string> calculateFiles(vector<RelativeVector *> UnclassifiedVectors,
                                  vector<ClassifiedRelativeVector *> classifiedVectors);

    // Creating a map to go over the sorted cataloged vector.
    map<string, int> createMap(vector<ClassifiedRelativeVector *> knn);

    // Getting the classification by the KNN.
    string extractClassification(const map<string, int> &kMap);

private:
    // The calculation for the distance.
    AbstractDistance *calc;
    // The K nearest neighbors.
    unsigned long kNeighbors;
    // The classified relative vectors.
    vector<ClassifiedRelativeVector *> catalogedVectors;
};

#endif //EX4_KNNALGORITHM_H
