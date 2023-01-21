#include "CLI.h"

#include <utility>

/**
 * Destructor for CLI class.
 */
CLI::~CLI() = default;

/**
 * Default constructor for CLI class.
 */
CLI::CLI() = default;

/**
 * A constructor for CLI class.
 * @param IO which IO we are going to use (standard IO or socket IO).
 */
CLI::CLI(AbstractDefaultIO *IO) {
    setDefaultIO(IO);
}

/**
 * Setter for IO member.
 * @param IO which IO we are going to use (standard IO or socket IO).
 */
void CLI::setDefaultIO(AbstractDefaultIO *IO) {
    this->defaultIo = IO;
}

/**
 * A getter for the IO member of CLI class.
 * @return the IO member.
 */
AbstractDefaultIO *CLI::getDefaultIO() {
    return this->defaultIo;
}

/**
 * A setter for the map that contain commands.
 * @param newCommand - Map that contains all the commands.
 */
void CLI::setCommands(map<string, Commander *> newCommand) {
    this->commands = std::move(newCommand);
}

/**
 * A getter for the map of commands.
 * @return Map that contains all the commands.
 */
map<string, Commander *> CLI::getCommands() {
    return this->commands;
}

/**
 * The control flow method - Printing the menu for the user, check his choice and execute this command.
 */
void CLI::start() {
    // Ger the IO.
    AbstractDefaultIO *dIO = getDefaultIO();
    // Creating the map with all the possibles commands.
    map<string, Commander *> commanders = initializeCommands(dIO);
    // SEt the member with the new map that contains all the possibles commands.
    setCommands(commanders);
    // Creating the menu.
    string menu = menuCreator();
    // Send the menu to the client.
    dIO->write(menu);
    // While tru to run the connection between the client and the server until the client ask to close the connection.
    while (true) {
        // Checking the user choice.
        string response = dIO->read();
        // Check if the user entered a valid choice and execute his request, otherwise sending the user error.
        Commander *command = processRequest(response);
        if (command == nullptr) {
            dIO->write("invalid input\n" + menu);
            continue;
        }
        command->execute();
        // Checking if the user want to close the connection to the server.
        if (response == "8" || response == "8\n") {
            break;
        }
    }

}

/**
 * Creating the menu for the user.
 * @return A string - menu string.
 */
string CLI::menuCreator() {
    // The start line of the menu.
    string menu = "Welcome to the KNN Classifier Server. Please choose an option:\n";
    // Getting the description of each command to add to the menu.
    menu += "1. " + this->commands["1"]->getDescription();
    menu += "2. " + this->commands["2"]->getDescription();
    menu += "3. " + this->commands["3"]->getDescription();
    menu += "4. " + this->commands["4"]->getDescription();
    menu += "5. " + this->commands["5"]->getDescription();
    menu += "8. " + this->commands["8"]->getDescription();
    // Set the menu to all commanders.
    this->commands["1"]->setMenu(menu);
    this->commands["2"]->setMenu(menu);
    this->commands["3"]->setMenu(menu);
    this->commands["4"]->setMenu(menu);
    this->commands["5"]->setMenu(menu);
    this->commands["8"]->setMenu(menu);
    // Rerun the complete menu.
    return menu;
}

/**
 * Creating the command ready to execute.
 * @param IO standard Io or socket Io.
 * @return A map that contains all the possibles commands.
 */
map<string, Commander *> CLI::initializeCommands(AbstractDefaultIO *IO) {
    // Init a map for all the commands.
    map<string, Commander *> initCommands;
    // Init all the commands by calling their constructor.
    Commander *uploadFile = new UploadFile("upload an unclassified csv data file\n", IO);
    Commander *algorithmSetting = new AlgorithmSetting("algorithm setting\n", IO);
    Commander *classifyData = new ClassifyData("classify data\n", IO);
    Commander *displayResult = new SendData("display results\n", IO);
    Commander *downloadResult = new SendToDownload("download results\n", IO);
    Commander *exit = new EndConnection("exit\n", IO);

    // Profiling a value for specific key ( by the order of the menu commands).
    initCommands["1"] = uploadFile;
    initCommands["2"] = algorithmSetting;
    initCommands["3"] = classifyData;
    initCommands["4"] = displayResult;
    initCommands["5"] = downloadResult;
    initCommands["8"] = exit;

    return initCommands;
}

/**
 * Checking the user choice of the menu, which command the user want to execute.
 * @param clientChoice string that the user entered (key).
 * @return The specify command the user want to execute.
 */
Commander *CLI::processRequest(string clientChoice) {
    clientChoice.pop_back();
    if (this->commands.find(clientChoice) == this->commands.end()) {
        return nullptr;
    }
    return this->commands[clientChoice];
}
