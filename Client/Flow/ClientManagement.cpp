#include "ClientManagement.h"
#include "../Operations/DownloadOp.h"


/**
 * A default constructor.
 */
ClientManagement::ClientManagement(int port, string ip) {
    setPort(port);
    setIp(std::move(ip));
}

/**
 * A default destructor.
 */
ClientManagement::~ClientManagement() = default;

/**
 * A constructor who receives a default io pointer.
 * @param dio The default io pointer.
 */
ClientManagement::ClientManagement(AbstractDefaultIO *dio) {
    setDefaultIO(dio);
}

/**
 * A setter for the port number of the server.
 * @param newPort The port number of the server.
 */
void ClientManagement::setPort(int newPort) {
    this->port = newPort;
}

/**
 * A getter for the port number of the server.
 * @return The current port number of the server.
 */
int ClientManagement::getPort() {
    return this->port;
}

/**
 * A setter for the server's ip.
 * @param ip The server's ip.
 */
void ClientManagement::setIp(string ip) {
    this->serverIp = ip;
}

/**
 * A getter for the server's ip.
 * @return The server's ip.
 */
string ClientManagement::getIp() {
    return this->serverIp;
}


/**
 * A getter for the DIO.
 * @return The DIO pointer of type AbstractDefaultIO.
 */
AbstractDefaultIO *ClientManagement::getDefaultIO() {
    return this->defaultIo;
}

/**
 * A setter for the default io.
 * @param dio The dio member of the class.
 */
void ClientManagement::setDefaultIO(AbstractDefaultIO *dio) {
    this->defaultIo = dio;
}

/**
 * Reading the user's input.
 * @return The user's input.
 */
string ClientManagement::userInput() {
    string line;
    getline(cin, line);
    return line;
}

/**
 * This method starts the client's operation with the server.
 */
void ClientManagement::start() {
    // Creating a socket creator.
    SocketCreator socketCreator(getPort());
    // Creating a new socket for the client.
    int clientSocket = socketCreator.makeNewSocket();
    // Creating a struct address for the socket.
    struct sockaddr_in sin = socketCreator.createAddrInStruct(getIp());
    // Connecting to the server.
    if (connect(clientSocket, (struct sockaddr *) &sin, sizeof(sin)) < ZERO_FLAG) {
        perror("Error connecting to server");
        exit(0);
    }
    // Creating a SocketIO for the client.
    AbstractDefaultIO *dio = new SocketIO(clientSocket);
    // Set the SocketIO to the client.
    setDefaultIO(dio);
    // Run the communication with the client.
    run();
    // Destroy the default io.
    delete getDefaultIO();
}

/**
 * Running the connection.
 */
void ClientManagement::run() {
    // While the client still want to, run the connection.
    while (true) {
        // Get a message from the server.
        string menu = getDefaultIO()->read();
        // If the menu management alerts to, close the connection.
        if (!menuManagement(menu)) {
            return;
        }
    }
}

/**
 * Printing the menu and managing the menu choice of the client.
 * @return The client's choice from the menu.
 */
bool ClientManagement::menuManagement(string menuStr) {
    // Print the menu.
    cout << menuStr;
    // Get the user's input.
    string line = userInput();
    if (line == "8") {
        // Send the server the "exit" choice to finish the connection and free resources.
        getDefaultIO()->write(line);
        return false;
    }
    // Check if the input is a valid integer.
    if (!this->clientValidation.validI(line)) { // ADD MENU CHOICES CHECK.
        // If it isn't, send it to the server making no operations.
        getDefaultIO()->write(line);
        return true;
    }
    // If the operation decided to be 3, it's just print so return.
    if (line == "3") {
        getDefaultIO()->write(line);
        return true;
    }
    // Send to the server the choice -->> !
    AbstractOperations *op = choiceProcess(line);
    // Sending the client's request to the server.
    getDefaultIO()->write(line);
    // Execute the operation.
    op->executeOp();
    // Delete the resources.
    delete op;
    return true;
}

/**
 * Processing what choice from the menu the user made, and (hopefully returning the choices operation).
 * @param choice The choice the user made (no manipulations made on it).
 */
AbstractOperations *ClientManagement::choiceProcess(string choice) {
    // Convert the choice to a number.
    int choiceNum = stoi(choice);
    switch (choiceNum) {
        case 1:
            return new UploadFilesOp(getDefaultIO());
        case 2:
            return new AlgorithmSettingOp(getDefaultIO());
        case 4:
            return new DisplayResult(getDefaultIO());
        case 5:
            return new DownloadOp(getDefaultIO());
        default:
            return nullptr;
    }
}
