#ifndef EX4_STANDARDIO_H
#define EX4_STANDARDIO_H

#include "AbstractDefaultIO.h"

/**
 * A standard IO class using the keyboard and the screen.
 */
class StandardIO : public AbstractDefaultIO {
public:
    // A default constructor.
    StandardIO();

    // A default destructor.
    ~StandardIO() override;

    // An implementation to read.
    string read() override;

    // An implementation to write.
    void write(string content);
};

#endif //EX4_STANDARDIO_H
