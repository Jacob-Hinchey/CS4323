//
//  FCFS.h
//  Assignment_04
//
//  Created by Jacob HInchey on 4/25/20.
//  Copyright © 2020 Jacob Hinchey. All rights reserved.
//

#ifndef FCFS_h
#define FCFS_h

#include <stdio.h>
typedef struct
{
    int pid;
    int burst_time;
    int waiting_time;
    int complete_time;
} Process;

void print_table(Process p[], int n);
void print_gantt_chart(Process p[], int n);
void firstcome();
#endif /* FCFS_h */
