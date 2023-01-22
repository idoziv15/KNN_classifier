#ifndef EX4_CLIENTVALIDATION_H
#define EX4_CLIENTVALIDATION_H


#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>


using namespace std;


/**
 * A validation class for the client.
 */
class ClientValidation {
public:

    // Checking if a number is in scientific notation.
    bool validD(const basic_string<char> &str);

    // Checking if the ip is valid.
    bool validIp(const string &ip);

    // Checking if the port number is valid.
    bool validPortNumber(const string &port);

    // Checking if a string can be converted to unsigned int.
    bool validUnsignedInt(const std::string &s);

    // Checking the full data the user entered.
    bool checkingUserInput(vector<string> userVecCheck);

    // Checking if a string is a valid integer.
    bool validI(string strNum);

    bool validPath(const string &path);

    // Checking if the choice by the user is valid.
    bool checkValidChoice(string line);

protected:

    // As we know ipv4 is separate to 4 cells check each one of them.
    bool validCellIpv4(const string &cell);

    // Checking if a string distance is a valid distance specifier.
    bool validDistance(const string &distanceSpec);

    // Checking if k_elements is a valid number.
    bool validKElements(const string &k_elements);

    // Checking if the doubles the user entered is valid doubles.
    bool checkVecDouble(vector<string> vector);


};

#endif //EX4_CLIENTVALIDATION_H
