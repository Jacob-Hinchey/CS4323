//Name: Jacob Hinchey
//EMail: Jacob.hinchey@okstate.edu
//Date: 04/10/2020

Files:
  Assignment03_Jacob_Hinchey_Question01.c
  Assignment03_Jacob_Hinchey_Question01.h

Description:
 This program is made to represt four different routers using arrays of ints. 
 Each buffer of the router is equal to a single packet.
 Each full buffer is represented by a 1, and empty is represented by 0.
 The initial router configeration used can be changed by adjusting the
 routA, routB, routC,and routD int arrays.
 The idea for handling deadlock was based mostly on banker's algorithm.
 This checks the availablity of the resources nessacary before trying to move the packets.
 It compares the amount of buffers available to the amount of buffers needed before making any moves.
 This program handles deadlock by terminating the current process.
 The code used to find deadlock ended up being very verbose in checking for deadlock in each case.


Compile:
  $gcc -o main Assignment03_Jacob_Hinchey_Question01.c

Run:
   ./main

Testing:
  This has been tested on MAC OSX and in the CSX machine

Assumptions:
 I assume the menu used in the program is appropriate for on the fly testing without having 
 To edit the actual code frequently. I also assume that the user is deciding how to move the 
 Packets and where they need to go. The program is made to handle movement from
 A->B->C->D->A