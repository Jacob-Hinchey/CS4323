//Name: Jacob Hinchey
//EMail: Jacob.hinchey@okstate.edu
//Date: 03/13/2020

Files:
  Assignment02_Jacob_Hinchey_Question01.c
  Assignment02_Jacob_Hinchey_Question01.h

Description:
  This program reads in a user input of a movie then takes it to find information
  about the movie from 4 different csv files. THis is done using both threads and
  no threads to compare

Setup:
  Open CSX and go to the correct directory tags.csv, movies.csv, rating.csv, and
  links.csv.

Compile:
  $gcc -pthread -w -o program2 Assignment02_Jacob_Hinchey_Question01.c

Run:
  ./program2

Testing:
  This has been tested on MAC OSX and in the CSX machine

Assumptions:
  I assume the information from the csvs can be stored in any way, so I store them
  into a struct from best data segregation.

Known issue:
  Throws seg fault when trying to read from movies csv file. This happens when
  using fgets,fscanf, or fscan.
