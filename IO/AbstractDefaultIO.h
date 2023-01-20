
#ifndef EX4_ABSTRACTDEFAULTIO_H
#define EX4_ABSTRACTDEFAULTIO_H

#include <cstdlib>
#include "string"
#include "iostream"

using namespace std;

/**
 * An abstract class for IO inheritance.
 */
class AbstractDefaultIO {
public:
    // A pure virtual method read that all the inheritance need to implement.
    virtual string read() = 0;
    // A pure virtual method write that all the inheritance need to implement.
    virtual void write(string content) = 0;
};

#endif //EX4_ABSTRACTDEFAULTIO_H
