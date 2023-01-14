

#ifndef EX4_DATAPROCESSING_H
#define EX4_DATAPROCESSING_H




#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "RelativeVector.h"
#include "ServerValidations.h"

using namespace std;

/**
 * A code sharing class to process data and strings.
 */
class DataProcessing {
public:

    // Creating a vector of strings, representing the cells in the file vector.
    vector<string> catchDelim(const string &fullVector, char delim);

    // Convert a vector of strings to a vector of doubles.
    vector<double> sTodVec(vector<string> strVec);

    // Create a vector that contains vector of strings.
    vector<vector<string>> createLinesArray(vector<string> lineVec);

    // Create a vector that contains vector of doubles.
    vector<vector<double>> linesToDoubles(vector<vector<string>> lines);

    // Create a vector that contains reference to relative vector.
    vector<RelativeVector*> doublesToRelatives(vector<vector<double>> doublesVec);


protected:
    // A server validation instance to use when processing the file.
    ServerValidations serverValidations;



};
#endif //EX4_DATAPROCESSING_H
