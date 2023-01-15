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


/**
 * Create a map contains the string of classification as a key and the number it appears in knn as a value.
 * @param knn The k nearest neighbours to the user's vector.
 * @return A map contains the string of classification as a key and the number it appears in knn as a value.
 */
map<string, int> KnnAlgorithm::createMap(vector<ClassifiedRelativeVector *> knn) {
    // Declare a map.
    map<string, int> kMap;
    for (int i = 0; i < knn.size(); i++) {
        // If the classification is in the map.
        if (kMap.find(knn[i]->getClassification()) != kMap.end()) {
            // Add one to the value.
            kMap[knn[i]->getClassification()] += 1;
            // If it's not.
        } else {
            // add the classification with the value 1.
            kMap[knn[i]->getClassification()] = 1;
        }
    }
    // Return the map.
    return kMap;
}

/**
 * Check what key has the biggest value, and return it's classification.
 * @param kMap Tha map of values.
 * @return the classification the biggest value.
 */
string KnnAlgorithm::extractClassification(const map<string, int> &kMap) {
    // A counter for the biggest classification.
    int maxClass = 0;
    // The result classification.
    string resultClass;
    // Iterate all keys.
    for (auto const &keyValue: kMap) {
        // If the value is larger than the counter, replace them.
        if (keyValue.second > maxClass) {
            maxClass = keyValue.second;
            resultClass = keyValue.first;
        }
    }
    // Return the largest classification.
    return resultClass;
}

/**
 * A control flow function for this class calculations.
 * @return the largest classification from the KNN vectors.
 */
string KnnAlgorithm::classifyVector(vector<double> unclassifiedVector) {
    // Calculate all distances of vectors from the user's vector.
    if (!calculateDistances(std::move(unclassifiedVector))) {
        return "";
    }
    // Calculate the k nearest neighbors.
    vector<ClassifiedRelativeVector *> nearestK = sortingAndGettingK();
    // Create a map from the knn.
    map<string, int> kMap = createMap(nearestK);
    // Calculate the largest classification and return it.
    return extractClassification(kMap);
}


/**
 * A comparator for the sort function between to RelativeVectors by their distance value.
 * @param v1 The first RelativeVector.
 * @param v2 The second RelativeVector.
 * @return True if the distance of v1's distance is lower then v2's, False otherwise.
 */
bool compareRelativeVector(ClassifiedRelativeVector *v1, ClassifiedRelativeVector *v2) {
    return (v1->getDistanceFromMasterVec() < v2->getDistanceFromMasterVec());
}

/**
 * Sorting the vector of RelativeVectors, taking only the first k elements.
 * @return A vector of the k smallest by distance elements.
 */
vector<ClassifiedRelativeVector *> KnnAlgorithm::sortingAndGettingK() {
    // Set the CatalogVectors to a temp vector.
    vector<ClassifiedRelativeVector *> knn = getCataloged();
    // Sort the array by the given compare function.
    sort(knn.begin(), knn.end(), compareRelativeVector);
    // Set the knn to the catalog vector.
    setCatalogVec(knn);
    // Create a new vector.
    vector<ClassifiedRelativeVector *> kRelativeVectors;
    // Push to it the first k elements.
    unsigned long kNum = getKNeighbors() > knn.size() ? knn.size() : getKNeighbors();
    for (int i = 0; i < kNum; i++) {
        kRelativeVectors.push_back(knn[i]);
    }
    // Return the first k elements.
    return kRelativeVectors;
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
    // Creating a result vector to store the classifications.
    vector<string> resultClassifications;
    // Setting the cataloged vector.
    setCatalogVec(std::move(classifiedVectors));
    // The classification of a specific vector.
    string classification;
    // Getting the amount of vectors to classify.
    unsigned int size = unclassifiedVectors.size();
    for (int i = 0; i < size; ++i) {
        // Getting the classification of a specific vector.
        classification = classifyVector(unclassifiedVectors[i]->getValuesVector());
        // If the classification is empty, return an empty vector.
        if (classification.empty()) {
            // Create and return the empty vector.
            vector<string> error;
            return error;
        }
        // Concatenate the result with the sequenced vector.
        resultClassifications.push_back(to_string(i) + " " + classification + "\n");
    }
    // Return the result.
    return resultClassifications;
}