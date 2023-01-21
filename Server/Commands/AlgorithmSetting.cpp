
#include "AlgorithmSetting.h"

#include <utility>

/**
 *  A default destructor for Algorithm Setting class.
 */
AlgorithmSetting::~AlgorithmSetting() = default;


/**
 * The constructor of AlgorithmSetting class.
 * @param description the description of the class.
 * @param Dio The IO.
 * @param database The general database.
 */
AlgorithmSetting::AlgorithmSetting(string description, AbstractDefaultIO *Dio,RelativeDatabase* database)
        : Commander(std::move(description), Dio,database) {

}

/**
 * Manging the flow of the command = Algorithm setting class.
 */
void AlgorithmSetting::execute() {
    // Sending to the user the current parameters of k element and the metric.
    getDio()->write("The current KNN parameters are: k = "
                    + to_string(getDatabase()->getKElement())
                    + ", distance metric = "
                    + getDatabase()->getMetric() + "\n");
    // Getting the user response.
    string response = getDio()->read();
    // Checking if he doesn't want to change the settings.
    if (response.empty() || response == "\n") {
        getDio()->write(getMenu());
        return;
    }
    // Getting the response into a vector for validation check.
    vector<string> extractedResponse = this->dataProcessing.catchDelim(response, ' ');
    string validError;
    // Checking the user response and write to the user if invalid.
    if (!this->serverValidations.validKAndMetric(validError, extractedResponse)) {
        getDio()->write(validError + getMenu());
        return;
    }
    // Setting the new k element
    getDatabase()->setKElement(stoi(extractedResponse[0]));
    // Setting the new metric.
    getDatabase()->setMetric(extractedResponse[1]);
    // Send the menu to the client.
    getDio()->write(getMenu());
}
