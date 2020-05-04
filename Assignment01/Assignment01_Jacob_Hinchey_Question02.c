//Name: Jacob Hinchey
//Email: jacob.hinchey@okstate.edu
//Date: 02/27/2020
//Description: This program reads in a user sentence, then divides that into individual words
//Each of these words is checked against a file database to see if it has already been
//entered before. If it is not the user is asked if they would like to add the word.


#include "Assignment01_Jacob_Hinchey_Question02.h"
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <fcntl.h>
#include <signal.h>

#define SHMSIZ 1000
int main(){
    //variable declorations
    key_t key1;
    int shmid;
    char *shm;
    char *ptr;
    int wordsAdd=0;
    int existingWords=0;
    int newWords = 0;
    char userText[30][30];
    char curr_dic[30][100];
    char askUser[30][30];
    FILE *IN_FILE;
    FILE *OUT_FILE;

    //create shared memory space
    //commented out one works on my mac but not csx
    key1 = getuid();

    shmid = shmget(9876, SHMSIZ, IPC_CREAT|0777);
    //shmid = shmget(key1, SHMSIZ, IPC_CREAT);

    //checks to  make sure shared memory is valid
    if(shmid < 0){
          printf("Error");
          exit(1);
      }
    //assign variable to hold shared mem data and check to make sure it's valid
    shm = shmat(shmid, NULL, 0);
    if(shm == (char*)-1){
        printf("error1");
        exit(1);
    }
    //infinate while loop
    while(1){
        //takes in user string and puts it into shared memory
        char user_input[100] = "";
        printf("Enter a sentence to add to the Dictionay:\n");
        fgets(user_input, 100, stdin);
        memcpy(shm, user_input, 100);
        //starts the second process
        pid_t childPID1 = fork();

        if (childPID1 >= 0) // fork was successful
        {
            if (childPID1 == 0) // child process
            {
                //separates the user input into individual words and counts them
                //DRAWS THE USER INPUT FROM SHARED MEMORY
                ptr = strtok(shm, " ");
               if(shm == (char*)-1){
                   printf("error1");
                   exit(1);
               }
                
                int i =0;
               while(ptr != NULL){
                   strcpy(userText[i], ptr);
                   ptr = strtok(NULL, " ");
                   i++;
                   wordsAdd++;
               }
                //reads in current dictionary from file and stores it in array
                i=0;
                IN_FILE = fopen("Dictionary.txt","r");
                char fromFile[20];
                while(strcmp(fgets(fromFile, 20, IN_FILE), "\0")){
                    if(!strcmp(fromFile, "\n")){
                        strcpy(curr_dic[i], fromFile);
                    }
                    i++;
                }

                //compares the user words to the current dictionary and adds new words to
                //an array of words not it dictionary is kept
                int j = 0;
                while(!strcmp(userText[j], NULL)){
                    int flag = 1;
                    int k =0;
                    while(!strcmp(curr_dic[k], NULL)){
                        if(strcmp(curr_dic[k],userText[j])){
                            flag = 0;
                        }
                        k++;
                    }
                    //keeps count of new words and existing words
                    if(flag == 0){
                        strcpy(askUser[j], userText[j]);
                        newWords++;
                    }
                    else{
                        existingWords++;
                    }
                    j++;

                }
                //kills child
                break;
            }
            else // Parent process
            {
                //waits until child is finished
                wait(NULL);
                //gives the details of the dictionary requested
                printf("Number of words in user text: %d\nNumber of words not matched in database: %d\nNumber of words matched in the database: %d\n", wordsAdd, newWords, existingWords);
                //loops and asks user if they want to add the new words to the dictionary
                int i =0;

                while(!strcmp(askUser[i],NULL)){
                    printf("Would you like to add %s to the dictionary?",askUser[i]);
                    printf("type y if yes.");
                    printf("Here1\n");

                    char toAdd[10]="";
                    scanf(toAdd, stdin);
                    if(strcmp(toAdd, "y")){
                        OUT_FILE = fopen("Dictionary.txt", "a+");
                        fprintf(OUT_FILE, "%s",askUser[i]);
                        fclose(OUT_FILE);
                    }
                    printf("Here\n");

                    i++;
                }
                //gives user a chance to quit program
                printf("Would you like to quit adding words?");
                printf("type y if yes.");
                char toAdd[10]="";
                scanf(toAdd, stdin);
                if(strcmp(toAdd, "y")){
                    printf("Would you like to delete the database?");
                    printf("type y if yes.");
                    scanf(toAdd, stdin);
                    if(strcmp(toAdd, "y")){
                        OUT_FILE = fopen("Dictionary.txt", "w");
                        fprintf(OUT_FILE, NULL);
                        fclose(OUT_FILE);
                    }
                    break;
                }
            }


        }
        else // fork failed
        {
            printf("\n Fork failed, quitting!!!!!!\n");
            return 1;
        }

        //These empty all the reused variables
        for(int i = 0; i<31;i++){
            strcpy(userText[i],NULL);
            strcpy(askUser[i],NULL);
        }
        for(int i = 0; i<100;i++){
            strcpy(curr_dic[i],NULL);
        }
        memcpy(shm, NULL, 100);
        wordsAdd=0;
        existingWords=0;
        newWords = 0;
    }

    return 0;
}
