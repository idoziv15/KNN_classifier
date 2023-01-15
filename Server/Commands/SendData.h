
#ifndef EX4_SENDDATA_H
#define EX4_SENDDATA_H

# include "Commander.h"

/**
 * This class responsible to send the data to the client.
 */
class SendData : public Commander {
public:
    // This method send classify data to the client (if the data exist), otherwise an error.
    void execute() override;

    SendData(string description, AbstractDefaultIO *Dio);

};

#endif //EX4_SENDDATA_H
