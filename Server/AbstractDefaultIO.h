
#ifndef EX4_ABSTRACTDEFAULTIO_H
#define EX4_ABSTRACTDEFAULTIO_H
#include <cstdlib>
#include "string"
#include "iostream"

using namespace std;

class AbstractDefaultIO{
public:
    virtual string read() = 0;
    virtual void write() = 0;
};
#endif //EX4_ABSTRACTDEFAULTIO_H
