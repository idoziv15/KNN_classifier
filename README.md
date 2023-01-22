<h1 align="center">
  <br>
  <a href="https://github.com/TalMizrahii/AP1Project"><img src="https://img.icons8.com/color/344/c-plus-plus-logo.png" alt="C++" width="200"></a>
  <br>
  Advanced-Programming-1
  <br>
</h1>

<h4 align="center">This github repository is for the final assignment given in Advanced Programming 1 course, Bar Ilan University.


<p align="center">
  <a href="#description">Description</a> •
  <a href="#implementation">Implementation</a> •
  <a href="#dependencies">Dependencies</a> •
  <a href="#installing-and-executing">Installing And Executing</a> •
  <a href="#authors">Authors</a> 
</p>

## Description

*The final project seats in the "main" branch!*

This program has two components, a Server and a client. The Server is a TCP server, which can receive two CSV files. One of the files contains vectors of doubles and a specific classification, and the other file contain vectors of doubles with no classification. The Client can connect to the server, enter a path to the files, and ask the server to calculate the classification of each vector from the unclassified file using [KNN algorithm](https://en.wikipedia.org/wiki/K-nearest_neighbors_algorithm) . The server can send to the client the result, and if the client wishes to, it can can send it to a file in the client's computer.

### The Client

The client receives two system arguments:
 * The IP address of the server.
 * The port number the server uses.
  
 After initiation, the client connects to the server. The server sends the client a menu, and from it, the client can choose a command for the server. 

  
The menu looks like this:
  
Welcome to the KNN Classifier Server. Please choose an option:
1. upload an unclassified csv data file.
2. algorithm settings.
3. classify data
4. display results
5. download results
8. exit


### The Server

The server receives two system arguments:
  
 * A path to the file database contains classified vectors in a CSV file.
 * The port number to use (needs to be an unused port number).
 
We use a given database named "datasets", containing .cvs files. Each row in a file represents a vector of doubles. The last cell in the row represents the classification of the vector. 
  
The server sets its socket to listen to 5 clients at most.

He processes the message from the client into 3 elements (in this order):

* 1. The vector - must be the same size as the vectors in the database.
* 2. The distance calculation was wanted to be used in the KNN algorithm.
* 3. The number K for the KNN algorithm.

The second argument (The distance calculation) is interpreted as:
  * MUN - [Taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry)
  * AUC - [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance)
  * CHB - [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance)
  * CAN - [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance)
  * MIN - [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance)
  
The third argument, the KNN, must be a positive number. If the K is larger then the number of vectors in the file, the algorithm will calaulate the maximum vectors he can from the database.

The server calculates the KNN and returns the classification to the client's socket. After that, the server waits for a new message from the client. If the client sends "-1", the server will close the client's socket and accept a new client. If the client sends any invalid message (not by format, invalid metric, etc), the server will reply with "invalid input".
  
A run example, server perspective:
  
<img width="367" alt="server" src="https://user-images.githubusercontent.com/103560553/210224382-9ade1708-43f9-436c-b2b4-22ab6cf80fb0.PNG">


## Implementation
  
### client

If the port number received as a system argument is not valid (negative or larger than 65,553) the program will close. Same as the port number, if the IP address is not a valid IP the program also will close.
  
The client uses the UserVectorInput class to get input from the user. All socket activity is made in the ClientSocket class, and the validations are made using the ClientValidations class.

### Server
The server contains two directories, Distances, and flowAndData.
  
Distances contain classes that represent every different calculation that can be performed in the KNN algorithm. It also contains the AbstarctDistances class, used for polymorphism between the calculations.

In the flowAndData, we created a RelativeVector class, which contains the vector of doubles and the classification for each row. We calculated the KNN in the KnnAlgorithm class using a hash map and returned the resulting classification. To access the database, we use the FileReader class, which inherits from the DataProcessing class, to read and extract the data to a vector of RelativeVectors.

All socket activity, run, and creation is made in the ServerSocket class. It also inherits from the DataProcessing class to use its methods of processing data. It also contains a member of type ServerValidation, to validate the data received from the client's socket.

## Dependencies

* The program tested for linux machines.
* Compiled with g++.

## Installing And Executing

To clone and run this application, you'll need [Git](https://git-scm.com) installed on your computer. From your command line (running on localhost and port number 12345 - change if necessary):

```bash
# Clone this repository.
$ git clone https://github.com/TalMizrahii/AP1Project3

# Go into the repository.
$ cd AP1Project3

# Compile using makefile.
$ make
```
  This command will create two .out files; server.out and client.out.
  
```bash
# To run the server with default iris database:
$ make run-server
```
To run the server with specific database:

```bash
# Run wine
$ make run-wine
```

```bash
# Run beans
$ make run-beans
```
  
To run the client:
  
```bash
$ make run-client
```

To clean the .out files:

```bash
$ make clean
```

## Authors
* [@Yuval Arbel](https://github.com/YuvalArbel1)
* [@Tal Mizrahi](https://github.com/TalMizrahii)

