//First Come First Serve, meaning the earlier the arrival time the earlier the process is completed
//Arrival time is always zero
//GeeksforGeeks Reference

#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"


void print_table(Process p[], int n)
{
    puts("+-----+------------+--------------+-----------------+");
    puts("| PID | Burst Time | Waiting Time | Completion Time |");
    puts("+-----+------------+--------------+-----------------+");

    for(int i=0; i<n; i++) {
        printf("| %2d  |     %2d     |      %2d      |        %2d       |\n"
               , p[i].pid, p[i].burst_time, p[i].waiting_time, p[i].complete_time );
        puts("+-----+------------+--------------+-----------------+");
    }
}

void print_gantt_chart(Process p[], int n)
{
    printf(" ");
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burst_time; j++)
            printf("--");
        printf(" ");
    }
    printf("\n|");

    //For each pid
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burst_time - 1; j++)
            printf(" ");
        printf("P%d", p[i].pid);
    for(int j=0; j<p[i].burst_time - 1; j++){
        printf(" ");
    }
    printf("|");
    }
    printf("\n ");

    //Print the  bottom
    for(int i=0; i<n; i++){
        for(int j=0; j<p[i].burst_time; j++){
            printf("--");
        }
        printf(" ");
    }
    printf("\n");

    printf("0");
    for(int i=0; i<n; i++) {
        for(int j=0; j<p[i].burst_time; j++){
            printf("  ");
        }
        if(p[i].complete_time > 9){
            printf("\b");
        }
        printf("%d", p[i].complete_time);
    }
    printf("\n\n");
}

void firstcome()
{
    Process p[100];
    int n;
    int wait_time = 0;

    printf("Enter total number of process: ");
    scanf("%d", &n);
    printf("\nEnter burst time for each process:\n");
    for(int i=0; i<n; i++) {
        p[i].pid = i+1;
        printf("P[%d] : ", i+1);
        scanf("%d", &p[i].burst_time);
        p[i].waiting_time = p[i].complete_time = 0;
    }

    // calculate waiting time and turnaround time
    p[0].complete_time = p[0].burst_time;

    for(int i=1; i<n; i++) {
        p[i].waiting_time = p[i-1].waiting_time + p[i-1].burst_time;
        p[i].complete_time = p[i].waiting_time + p[i].burst_time;
    }

    // calculate sum of waiting time and sum of turnaround time
    for(int i=0; i<n; i++) {
        wait_time += p[i].waiting_time;
        wait_time += p[i].complete_time;
    }

    puts("");
    print_table(p, n);
    puts("");
    printf("Average Waiting Time: %-2.2lf\n", (double)wait_time / (double) n);
    printf("Average Turnaround Time: %-2.2lf\n", (double)wait_time / (double) n);
    puts(""); // Empty line
    puts("          * GANTT CHART *      ");
    puts(""); // Empty line
    print_gantt_chart(p, n);
}
