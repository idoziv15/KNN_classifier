#include "Server/ServerFlow/CLI.h"
#include "./IO/StandardIO.h"

/**
 * The main function of the server.
 * @return 0;
 */
int main() {
    AbstractDefaultIO *standardIo = new StandardIO();
    CLI cli(standardIo);
    cli.start();
    return 0;
}