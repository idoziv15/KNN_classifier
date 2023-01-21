#include "DataAndCalcs/ClientValidation.h"
#include "Flow/ClientManagement.h"


/**
 * Extracting arguments from the system args to be the K (for the knn algorithm), the path to the file (the database)
 * and the metric calculation.
 * @param argcArray The sysargs array.
 * @return A vector of those arguments.
 */
vector<string> extract_argc(char *argcArray[]) {
    ClientValidation v;
    // As we know the argc[0] is the program name, and by the format argc[1] is the ip address.
    string ip = argcArray[1];
    // Checking if the ip address legal.
    if (!v.validIp(ip)) {
        perror("Illegal IP.");
        exit(0);
    }
    // As we know the argc[0] is the program name, and by the format argc[2] is the port.
    string port = argcArray[2];
    // Checking if the port number legal.
    if (!v.validPortNumber(port)) {
        perror("Illegal port.");
        exit(0);
    }
    vector<string> vector;
    vector.push_back(ip);
    vector.push_back(port);
    return vector;
}

/**
 * The main function of the client.
 * @return 0;
 */
int main(int args, char *argv[]) {

    // Getting the argc and checking if valid.
    vector<string> argc_vector = extract_argc(argv);
    string ipAddress = argc_vector[0];
    int portNumber = stoi(argc_vector[1]);
    ClientManagement clientManagement(portNumber, ipAddress);
    clientManagement.start();

    return 0;
}