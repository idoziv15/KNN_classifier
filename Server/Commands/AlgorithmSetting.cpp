
#include "AlgorithmSetting.h"

#include <utility>

/**
 *  A default destructor for Algorithm Setting class.
 */
AlgorithmSetting::~AlgorithmSetting() = default;

AlgorithmSetting::AlgorithmSetting(string description, AbstractDefaultIO *Dio)
        : Commander(std::move(description), Dio) {

}


/**
 * Manging the flow of the command = Algorithm setting class.
 */
void AlgorithmSetting::execute() {
    // Sending to the user the current parameters of k element and the metric.
    getDio()->write("The current KNN parameters are: k = "
                    + to_string(getDatabase()->getKElement())
                    + ", distance metric = "
                    + getDatabase()->getMetric());
    // Getting the user response.
    string response = getDio()->read();
    // Checking if he doesn't want to change the settings.
    if (response.empty() || response == "\n") {
        return;
    }
    // Getting the response into a vector for validation check.
    vector<string> extractedResponse = this->dataProcessing.catchDelim(response, ' ');
    string validError;
    // Checking the user response and write to the user if invalid.
    if (!this->serverValidations.validKAndMetric(validError, extractedResponse)) {
        getDio()->write(validError);
        return;
    }
    // Setting the new k element
    getDatabase()->setKElement(stoi(extractedResponse[0]));
    // Setting the new metric.
    getDatabase()->setMetric(extractedResponse[1]);
}
