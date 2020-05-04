//This code runs the round robin portion which gives each process equal time to run regaurdless of outside factors
//GeeksforGeeks Reference

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "RoundRobin.h"
 
// Find completion time
void findTurnAroundTime(int processes[], int n,
                        int back[], int white[], int comp[])
{
    for (int i = 0; i < n ; i++){
        comp[i] = back[i] + white[i];
    }
}
 
// Function to calculate average time
void findavgTime(int processes[], int n, int bt[], int quantum)
{
    int white[n], tat[n], total_wt = 0, total_tat = 0;
 
    // Function to find turn around time for all processes
    findTurnAroundTime(processes, n, bt, white, tat);
 
    // Calculate total waiting time and total turn
    // around time
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + white[i];
        total_tat = total_tat + tat[i];
    }

    // print table
    puts(""); // Empty line
    print_rr(processes, n, bt, white, tat);
    puts(""); // Empty Line
    printf("Average Waiting Time: %-2.2lf\n", (double)total_wt / (double) n);
    printf("Average Completion Time: %-2.2lf\n", (double)total_tat / (double) n);
}
 

void print_rr(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[]){
    int  temp;

    puts("+-----+------------+--------------+-----------------+");
    puts("| PID | Burst Time | Waiting Time | Completion Time |");
    puts("+-----+------------+--------------+-----------------+");

    for (int i = 0; i < n; i++){
        for (int j = 0; j < (n - i - 1); j++){
            if (processes[j] > processes[j + 1]){
                temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;

                temp=burst_time[j];
                burst_time[j]=burst_time[j+1];
                burst_time[j+1]=temp;
         
                temp = waiting_time[j];
                waiting_time[j] = waiting_time[j + 1];
                waiting_time[j + 1] = temp;

                temp = turnaround_time[j];
                turnaround_time[j] = turnaround_time[j + 1];
                turnaround_time[j + 1] = temp;
            }
        }
    }


    for(int i=0; i<n; i++) {
    printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
           , processes[i], burst_time[i], waiting_time[i], turnaround_time[i]);
    puts("+-----+------------+--------------+-----------------+");
    }
}

// Main
void RR(){
    int processes[100];
    int burst_time[100];
    int quantum = 0, n = 0;

    printf("Enter total number of process: ");
    scanf("%d", &n);

    printf("\nEnter Burst Time for each process:\n");

    for(int i=0; i<n; i++) {
        processes[i] = i+1;
        printf("Burst Time of P[%d] : ", i+1);
        scanf("%d", &burst_time[i]);
    }

    printf("Enter time Quantum: ");
    scanf("%d", &quantum);


    findavgTime(processes, n, burst_time, quantum);
}
