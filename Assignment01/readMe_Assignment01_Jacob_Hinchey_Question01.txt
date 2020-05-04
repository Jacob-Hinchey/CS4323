//Name: Jacob Hinchey
//EMail: Jacob.hinchey@okstate.edu
//Date: 02/27/2019

Files:
  Assignment01_Jacob_Hinchey_Question01_Server.c
  Assignment01_Jacob_Hinchey_Question01_Client.c
  Assignment01_Jacob_Hinchey_Question01_Server.h
  Assignment01_Jacob_Hinchey_Question01_Client.h
  fortunes.txt

Description:
  These programs create a socket connection between each other to communicate.
  The Client reaches out to the server, and the server returns a fortune from
  fortune.txt. These fortunes are the type you would expect to find
  in a fortune cookie. The user should only need to type in the Client program.

Setup:
  Open two different terminals in the same directory. Ensure fortunes.txt,
  Assignment01_Jacob_Hinchey_Question01_Server.c and
  Assignment01_Jacob_Hinchey_Question01_Client.c are in the same directory.
  Compile and run the Server in one terminal then compile and run the client
  in the other terminal.

Compile:
  $gcc -o Server Assignment01_Jacob_Hinchey_Question01_Server.c
  $gcc -o Server Assignment01_Jacob_Hinchey_Question01_Client.c

Run:
  Terminal 1:
    ./Server
  Terminal 2:
    ./Client

Testing:
  This has been tested on MAC OSX and in the CSX machine

Assumptions:
  As specified in class, these need to be two separate files so testing could
  confirm that the server can manage 50 separate clients. Additional
  clients can be tested by opening more terminals. This must be done with two
  separate terminals as discussed in Class.
