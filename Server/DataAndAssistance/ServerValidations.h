#ifndef EX4_SERVERVALIDATIONS_H
#define EX4_SERVERVALIDATIONS_H

#include <cstdlib>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * A validation class for the server.
 */
class ServerValidations {
public:
    // Check if a file is on the server using given path.
    bool validPath(const string &path);

    // Checking if the last char is space or not.
    string isLastSpace(string classification);

    // A validation for a dot method.
    string isDot(string toNum);

    // Checking if the string is a valid double number.
    bool validD(const string &strToD);

    // Checking if a sting is a number.
    bool validI(const std::string &strNum);

    // Checking if the K element is valid.
    bool validK(const std::string &strNum);

    // Check if a strung is a valid port or not.
    bool validPortNumber(const string &port);

    // Check if the metric is valid.
    bool validMetric(string metric);

    // Checking the user setting input.
    bool validKAndMetric(string &responseError, vector<string> extractedResponse);
};

#endif //EX4_SERVERVALIDATIONS_H
