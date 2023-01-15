#ifndef EX4_ENDCONNECTION_H
#define EX4_ENDCONNECTION_H

#include "Commander.h"
/**
 * This class end the connection between the server and the client.
 */
class EndConnection : public Commander{
public:
    // THis method do all needed to close the connection with the client.
    void execute() override;

};
#endif //EX4_ENDCONNECTION_H
