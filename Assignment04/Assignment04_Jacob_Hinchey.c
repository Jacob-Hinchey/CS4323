//Name: Jacob Hinchey
//Date: 4/30/2020
//Email: jacob.hinchey@okstate.edu
//This program is made to demonstrait different types of schdeuling stratagies for a CPU.
//These stratagies are FCFS, Round Robin, Rate-Monotonic, and Earliest deadline first




#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "FCFS.h"
#include "FCFS.c"
#include "RoundRobin.h"
#include "RoundRobin.c"
#include "Earliest.c"
#include "Rate-Mono.c"


int main(){
    int flag = 0;
    //Menu
    while(flag == 0){
        char user_choice[10] = "";
        printf("\n1.First-come, first served\n2.Round-robin\n3.Rate-monotonic\n4.Earliest-deadline first scheduling\n5.Quit\n");
        scanf("%s", user_choice);
        //For FCFS
        if(strcmp(user_choice,"1") == 0){
            firstcome();
        }
        //Round Robin
        else if(strcmp(user_choice,"2") == 0){
            RR();
        }
        //Rate-Monotonic
        else if(strcmp(user_choice,"3") == 0){
            RMS();
        }
        //Earliest-Deadline First
        else if(strcmp(user_choice,"4") == 0){
            EDF();
        }
        else if(strcmp(user_choice,"5") == 0){
            break;
        }
        else{
            printf("\nNot a valid option\n");
        }
    }
    return(0);
}
