#ifndef EX4_STANDARDIO_H
#define EX4_STANDARDIO_H

#include "AbstractDefaultIO.h"


class StandardIO : public AbstractDefaultIO {
public:
    StandardIO();

    ~StandardIO();

    string read() override;

    void write(const string &content);
};

#endif //EX4_STANDARDIO_H
