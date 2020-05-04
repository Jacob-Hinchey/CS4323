//
//  RoundRobin.h
//  Assignment_04
//
//  Created by Jacob HInchey on 4/25/20.
//  Copyright © 2020 Jacob Hinchey. All rights reserved.
//

#ifndef RoundRobin_h
#define RoundRobin_h

#include <stdio.h>

void print_rr(int processes[], int n, int burst_time[], int waiting_time[], int turnaround_time[]);
int findWaitingTime(int processes[], int n, int bt[], int wt[], int quantum);
void findTurnAroundTime(int processes[], int n, int bt[], int wt[], int tat[]);
void findavgTime(int processes[], int n, int bt[], int quantum);
void RR();
#endif /* RoundRobin_h */
