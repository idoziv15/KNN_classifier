#include "DataProcessing.h"

/**
 * A method witch convert a string to a vector of string, separating by a given token.
 * @param fullVector The string to separate.
 * @param delim The token.
 * @return The vector witch represent the string. separated.
 */
vector<string> DataProcessing::catchDelim(string fullVector, char delim) {
    // Create a new stream to go over the line.
    istringstream line(fullVector);
    // Initiate a string to store the data from the vector.
    string fromDelim;
    // Create a vector of strings, representing the cells in the file vector.
    vector<string> strVec = vector<string>();
    // Go over the string from the file and separate its values to a new vector.
    while (getline(line, fromDelim, delim)) {
        strVec.push_back(fromDelim);
    }
    return strVec;
}

/**
 * Converting a vector of strings to a vector of doubles.
 * @param strVec The vector of strings.
 * @return The vector of doubles.
 */
vector<double> DataProcessing::sTodVec(vector<string> strVec) {
    // The new vector of doubles.
    vector<double> numVec;
    // Save the size of strVec.
    unsigned int iter = strVec.size();
    // Go over all the string representing a double in this vector.
    for (int i = 0; i < iter; ++i) {
        // Set the current string in strToD.
        string strToD = strVec[i];
        // Check it in isDot for validation.
        strToD = serverValidations.isDot(strToD);
        // If the string is valid to conversion, convert.
        if (serverValidations.validD(strToD)) {
            // Put the number in the double's vector.
            numVec.push_back(stod(strToD));
        }
    }
    return numVec;
}

/**
 * This method create a vector that contains vector of string using ',' delim.
 * @param LineVec - Vector of strings.
 * @return Vector that contains vector of strings.
 */
vector<vector<string>> DataProcessing::createLinesArray(vector<string> lineVec) {
    // Getting lineVec size.
    unsigned int lineVecSize = lineVec.size();
    // Init vector.
    vector<vector<string>> lines;
    for (int i = 0; i < lineVecSize; ++i) {
        vector<string> newLine;
        // Calling catchDelim to separate the string to different vectors of string.
        createVecVec(lineVec[i], ' ', newLine);
        lines.push_back(newLine);
    }
    return lines;
}

/**
 * Inserting string seperated by a specific delim to a vector of strings.
 * @param fullVec The string to convert.
 * @param delim The token separating the values in the string.
 * @param dest The result vector.
 */
void DataProcessing::createVecVec(string fullVec, char delim, vector<string> &dest) {
    // Create a new stream to go over the line.
    istringstream line(fullVec);
    // Initiate a string to store the data from the vector.
    string fromDelim;
    // Go over the string from the file and separate its values to a new vector.
    while (getline(line, fromDelim, delim)) {
        dest.push_back(fromDelim);
    }
}

/**
 * This method create a vector that contains vector of doubles.
 * @param lines vector that contains vector of strings.
 * @return vector that contains vector of doubles.
 */
void DataProcessing::linesToDoubles(vector<vector<string>> lines, vector<vector<double>> &dest) {
    // Getting lines size.
    unsigned int lineVecSize = lines.size();
    for (int i = 0; i < lineVecSize; ++i) {
        // Calling the sToVec function to create a vector of doubles.
        dest.push_back(sTodVec(lines[i]));
    }
}

/**
 * This method create a vector that contain a references to relativeVector.
 * @param doublesVec vector that contains vector of doubles.
 * @return vector of reference to relative vectors.
 */
vector<RelativeVector *> DataProcessing::doublesUnclassifiedRelatives(vector<vector<double>> doublesVec) {
    // Getting doublesVec size.
    unsigned int doublesVecSize = doublesVec.size();
    // Init vector.
    vector<RelativeVector *> relatives;
    relatives.reserve(doublesVecSize);
    for (int i = 0; i < doublesVecSize; ++i) {
        // Creating new RelativeVector on the heap.
        relatives.push_back(new RelativeVector(doublesVec[i]));
    }
    return relatives;
}

/**
 * Creating a ClassifiedRelativeVector from a vector of vector of doubles ans a vector of classifications.
 * @param doublesVec The values vector of vector of doubles.
 * @param classifications The array of classifications according to the doubles vectors.
 * @return An array of Classified relative vectors.
 */
vector<ClassifiedRelativeVector *> DataProcessing::doubleToClassifiedRelatives(vector<vector<double>> doublesVec,
                                                                               vector<string> classifications) {

    // Getting doublesVec size.
    unsigned int doublesVecSize = doublesVec.size();
    // Init vector.
    vector<ClassifiedRelativeVector *> relatives;
    relatives.reserve(doublesVecSize);
    for (int i = 0; i < doublesVecSize; ++i) {
        // Creating new RelativeVector on the heap.
        relatives.push_back(new ClassifiedRelativeVector(doublesVec[i], classifications[i]));
    }
    return relatives;
}
