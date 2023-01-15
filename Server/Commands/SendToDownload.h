#ifndef EX4_SENDTODOWNLOAD_H
#define EX4_SENDTODOWNLOAD_H

#include "Commander.h"
/**
 * This class is a command class that send the classify data to the user ready to downloading to his computer.
 */
class SendToDownload : Commander{
public:
    // Sending the classified data to the user if valid, otherwise sending an error.
    void execute() override;

};
#endif //EX4_SENDTODOWNLOAD_H
