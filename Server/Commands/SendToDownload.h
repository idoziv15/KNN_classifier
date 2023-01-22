#ifndef EX4_SENDTODOWNLOAD_H
#define EX4_SENDTODOWNLOAD_H

#include "Commander.h"

/**
 * This class is a command class that sends the classified data to the user, ready to download it to his computer.
 */
class SendToDownload : public Commander {
public:
    // Sending the classified data to the user if valid, otherwise sending an error.
    void execute() override;

    // Sending the data in the specified format.
    SendToDownload(string description, AbstractDefaultIO *Dio, RelativeDatabase* database);

};

#endif //EX4_SENDTODOWNLOAD_H
