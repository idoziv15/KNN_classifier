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

/**
 * A setter for the cataloged vector.
 * @param catalogVectors The new catalog vector.
 */
void KnnAlgorithm::setCatalogVec(vector<ClassifiedRelativeVector *> catalogVectors) {
    this->catalogedVectors = catalogVectors;
}

/**
 *  A getter for the catalog vector.
 * @return The catalog vector.
 */
vector<ClassifiedRelativeVector *> KnnAlgorithm::getCataloged() {
    return this->catalogedVectors;
}


/**
 * Given two files (as relativeVectors) calculating classifications for all unclassified files.
 * @param UnclassifiedVectors The unclassified vectors.
 * @param classifiedVectors The classified vectors.
 * @return A vector of strings representing the classifications of all unclassified vectors.
 * If the value is an empty vector, it means an error accord.
 */
vector<string> KnnAlgorithm::calculateFiles(vector<RelativeVector *> unclassifiedVectors,
                                            vector<ClassifiedRelativeVector *> classifiedVectors) {
    vector<string> resultClassifications;
    // Setting the cataloged vector.
    setCatalogVec(std::move(classifiedVectors));
    string classification;
    unsigned int size = unclassifiedVectors.size();
    for(int i = 0; i < size; ++i){
        classification = classifyVector(unclassifiedVectors[i]->getValuesVector());
        if(classification.empty()){
            vector<string> error;
            return error;
        }
        resultClassifications.push_back(to_string(i) + " " + classification);
    }
    return resultClassifications;
}

/**
 * The function check if two vectors are equally sized.
 * @param v1 The first vector.
 * @param v2 The second vector.
 * @return A boolean true if they are equally sized, false otherwise.
 */
bool KnnAlgorithm::sizeComparison(const vector<double> &v1, const vector<double> &v2) {
    // Checking if the vectors have the same size.
    return (v1.size() == v2.size());
}

/**
 * Calculate the distance between all vectors to the userVector and set them the result.
 * @return true if the calculation worked, false otherwise.
 */
bool KnnAlgorithm::calculateDistances(vector<double> uVec) {
    // Get the size of the cataloged vector.
    unsigned int size = getCataloged().size();
    // This for loop calc the distance between userVector(user input) to all the cataloged vectors.
    for (int i = 0; i < size; i++) {
        // Checking if the vectors in the same size.
        if (!sizeComparison(getCataloged()[i]->getValuesVector(), uVec)) {
            return false;
        }
        // Set the result of the distance between the user's vector to the ith vector.
        double result = getCalc()->calculateDistance(getCataloged()[i]->getValuesVector(), uVec);
        // Set the result to the ith vector.
        getCataloged()[i]->setDistanceFromMasterVec(result);
    }
    return true;
}


string KnnAlgorithm::classifyVector(vector<double> unclassifiedVector) {
    // Calculate all distances of vectors from the user's vector.
    if (!calculateDistances(std::move(unclassifiedVector))) {
        return "";
    }
    // Calculate the k nearest neighbors.
    vector<RelativeVector *> nearestK = sortingAndGettingK();
    // Create a map from the knn.
    map<string, int> kMap = createMap(nearestK);
    // Destroy the KNN vector.
    destroyKnn();
    // Delete the calculation metric.
    AbstractDistance *metric = getCalc();
    delete metric;
    // Calculate the largest classification and return it.
    return extractClassification(kMap);
}

/**
 * Sorting the vector of RelativeVectors, taking only the first k elements.
 * @return A vector of the k smallest by distance elements.
 */
vector<RelativeVector *> KnnAlgorithm::sortingAndGettingK() {
    // Set the CatalogVectors to a temp vector.
    vecto< *> knn = getCataloged();
    // Sort the array by the given compare function.
    sort(knn.begin(), knn.end(), compareRelativeVector);
    // Set the knn to the catalog vector.
    setCatalogedVectors(knn);
    // Create a new vector.
    vector<RelativeVector *> kRelativeVectors;
    // Push to it the first k elements.
    unsigned long kNum = min(getKNeighbors(), knn.size());
    for (int i = 0; i < kNum; i++) {
        kRelativeVectors.push_back(knn[i]);
    }
    // Return the first k elements.
    return kRelativeVectors;
}

