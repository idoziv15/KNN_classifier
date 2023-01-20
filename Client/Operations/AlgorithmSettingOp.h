#ifndef EX4_ALGORITHMSETTINGOP_H
#define EX4_ALGORITHMSETTINGOP_H

#include "AbstractOperations.h"


using namespace std;

class AlgorithmSettingOp : public AbstractOperations {

    explicit AlgorithmSettingOp(AbstractDefaultIO *defaultIo);

    ~AlgorithmSettingOp();

    void executeOp() override;
};


#endif //EX4_ALGORITHMSETTINGOP_H
