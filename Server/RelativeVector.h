
#ifndef EX4_RELATIVEVECTOR_H
#define EX4_RELATIVEVECTOR_H

#include <cstdlib>
#include <vector>
#include <string>
#include <utility>

using namespace std;

/**
 * A class representing a vector by name and values.
 */
class RelativeVector {

public:
    // A constructor receiving a vector of doubles.
    explicit RelativeVector(vector<double> initValuesVector);

    // A constructor.
    RelativeVector();

    // A destructor.
    ~RelativeVector();

    // A setter.
    void setValuesVector(vector<double> newValuesVector);

    // A getter.
    vector<double> getValuesVector();

private:
    // The vector of doubles.
    vector<double> valuesVector;
};

#endif //EX4_RELATIVEVECTOR_H
