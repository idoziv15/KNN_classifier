#ifndef EX4_KNNALGORITHM_H
#define EX4_KNNALGORITHM_H

#include "Server/Distances/AbstractDistance.h"
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

class KnnAlgorithm {
public:
    KnnAlgorithm(AbstractDistance *calculation, unsigned long kNum);

    ~KnnAlgorithm();

    void setKNeighbors(unsigned long kNum);

    void setCalc(AbstractDistance *calculation);

    unsigned long getKNeighbors();

    AbstractDistance *getCalc();

    void setCatalogVec(vector<ClassifiedRelativeVector *> catalogVectors);

    vector<ClassifiedRelativeVector *> getCataloged();

    string classifyVector(vector<double> unclassifiedVector);

    bool calculateDistances(vector<double> uVec);

    // Sorting the vector by distances.
    vector<ClassifiedRelativeVector *> sortingAndGettingK();

    // Check validation of the vectors.
    bool sizeComparison(const vector<double> &v1, const vector<double> &v2);

    vector<string> calculateFiles(vector<RelativeVector *> UnclassifiedVectors,
                                  vector<ClassifiedRelativeVector *> classifiedVectors);

    map<string, int> createMap(vector<ClassifiedRelativeVector *> knn);

    void destroyKnn();

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
