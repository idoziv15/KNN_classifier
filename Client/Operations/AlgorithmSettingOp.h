#ifndef EX4_ALGORITHMSETTINGOP_H
#define EX4_ALGORITHMSETTINGOP_H

#include "AbstractOperations.h"

using namespace std;

/**
 * An operation responsible to get input from the user about the settings of the Knn algorithm.
 */
class AlgorithmSettingOp : public AbstractOperations {
public:
    // A constructor for the class.
    explicit AlgorithmSettingOp(AbstractDefaultIO *defaultIo);

    // A destructor overriding the inherited class.
    ~AlgorithmSettingOp() override;

    // The implementation to the execute operation.
    void executeOp() override;
};

#endif //EX4_ALGORITHMSETTINGOP_H
