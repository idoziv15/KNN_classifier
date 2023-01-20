#include "ClassifyData.h"

/**
 *  Destructor for ClassifyData class.
 */
ClassifyData::~ClassifyData() = default;

/**
 * A constructor which pass the arguments he receives to the commander constructor.
 * @param description the description of the command.
 * @param newDescription Which IO we are gonna use.
 */
ClassifyData::ClassifyData(string description, AbstractDefaultIO *newDescription)
        : Commander(std::move(description), newDescription) {

}

/**
 * Control flow method - ClassifyData is a commander.
 */
void ClassifyData::execute() {
    // Checking if the user didn't upload any files.
    if (getDatabase()->getClassifiedRelatives().empty() || getDatabase()->getUnclassifiedRelatives().empty()) {
        getDio()->write("please upload data\n" + getMenu());
        return;
    }
    // Creating a distance object.
    AbstractDistance *disCalc = distanceCreator(getDatabase()->getMetric());
    // Creating Knn object to classify data.
    KnnAlgorithm knnAlgorithm(disCalc, getDatabase()->getKElement());
    // Getting the Knn result.
    vector<string> classifyData = knnAlgorithm.calculateFiles(getDatabase()->getUnclassifiedRelatives(),
                                                              getDatabase()->getClassifiedRelatives());
    // Delete the distance metric.
    delete disCalc;
    // Checking if was any error while getting classification in the knn algorithm.
    if (classifyData.empty()) {
        getDio()->write("invalid input\n" + getMenu());
        return;
    }
    getDatabase()->setResultVec(classifyData);
    // Classification complete successfully.
    getDio()->write("classifying data complete\n" + getMenu());
}


/**
 * Returning the distance object (on the heap) as the user specified.
 * @param distanceSpec The user's request.
 * @return The instance of the distance.
 */
AbstractDistance *ClassifyData::distanceCreator(const string &distanceSpec) {
    // Return the Euclidean distance.
    if (distanceSpec == "AUC") {
        auto *euc = new Euclidean();
        return euc;
    }
    // Return the Taxicab distance.
    if (distanceSpec == "MAN") {
        auto *man = new Taxicab();
        return man;
    }
    // Return the Chebyshev distance.
    if (distanceSpec == "CHB") {
        auto *chb = new Chebyshev();
        return chb;
    }
    // Return the Canberra distance.
    if (distanceSpec == "CAN") {
        auto *can = new Canberra();
        return can;
    }
    // Return the Minkowski distance.
    if (distanceSpec == "MIN") {
        auto *min = new Minkowski();
        return min;
    }
    // Set a default metric to return.
    auto *euc = new Euclidean();
    return euc;
}