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
  
  <img width="368" alt="1" src="https://user-images.githubusercontent.com/103560553/213907301-233a977c-a5b1-49f8-b42c-97fd3f332baa.PNG">


The user can choose any option from the menu. If he enters a choice outside of the menu, the server will reply "invalid input" message and will send the menu again.
  
In the first option, the user will be asked to upload files to the server. He will be asked to enter a path to a classified CSV file, and a path to an unclassified CSV file. The client will automatically send the content of the files to the server. This option will look like that:


  <img width="368" alt="3" src="https://user-images.githubusercontent.com/103560553/213906933-1b0cd068-c3dc-4808-a286-e36b1b564603.PNG">

  
If the user asks for the algorithm settings, the server will send him the current settings of the KNN algorithm. The message with the default settings looks like that:

<img width="370" alt="2" src="https://user-images.githubusercontent.com/103560553/213906987-efa9ee9f-1935-4b0d-860b-9d322b0b5018.PNG">
  
If he wants no changes to be made, he can press ENTER and the server will send the menu again. If the user wants to change the settings, he can enter a new K element, and a metric of his choice from these options:
  
  
  * MUN - [Taxicab geometry](https://en.wikipedia.org/wiki/Taxicab_geometry)
  * AUC - [Euclidean distance](https://en.wikipedia.org/wiki/Euclidean_distance)
  * CHB - [Chebyshev distance](https://en.wikipedia.org/wiki/Chebyshev_distance)
  * CAN - [Canberra distance](https://en.wikipedia.org/wiki/Canberra_distance)
  * MIN - [Minkowski distance](https://en.wikipedia.org/wiki/Minkowski_distance)

 In the third option, the client can just classify the data in the server. If no files were uploaded, the server will reply with an error message, and send the menu again. This part will look like this:
  
  
<img width="285" alt="4" src="https://user-images.githubusercontent.com/103560553/213907466-b97fdb4d-20e7-4e9c-8049-776ea83f8145.PNG">


  In option number 4, the client can request the result of the classification. The server will send the client the result of each vector in the order he received it. If no classification command is performed or no files were uploaded, the server will send an error message. The result will be displayed like that:
  
<img width="288" alt="5" src="https://user-images.githubusercontent.com/103560553/213907770-2840113a-7d60-48f5-8dd0-2fcc5e75d638.PNG">



### The Server

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

