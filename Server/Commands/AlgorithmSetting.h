

#ifndef EX4_ALGORITHMSETTING_H
#define EX4_ALGORITHMSETTING_H

#include "Commander.h"

/**
 * This class is a command - Responsible for the knn algorithm setting (distance metric and k neighbours).
 */
class AlgorithmSetting : public Commander {
public :

    // Constructor for algorithm setting class.
    AlgorithmSetting();

    // Destructor for algorithm setting class.
    ~AlgorithmSetting();

    // Execute the class by changing the algorithm setting.
    void execute() override;


};


#endif //EX4_ALGORITHMSETTING_H
