#include "IO/CLI.h"
#include "IO/StandardIO.h"

int main() {
    AbstractDefaultIO* standardIo = new StandardIO();
    CLI cli(standardIo);
    cli.start();
    return 0;
}