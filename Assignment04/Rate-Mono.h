//
//  Rate-Mono.h
//  Assignment_04
//
//  Created by Jacob HInchey on 4/25/20.
//  Copyright © 2020 Jacob Hinchey. All rights reserved.
//

#ifndef Rate_Mono_h
#define Rate_Mono_h

#include <stdio.h>
struct task{
    int period;
    float utilisation;
    int executionTime;
    int occurence;
    int executing;
    int priority;
}task;

int rm_scheduling(struct task mySet[],struct task tmpSet[],struct task svgSet[], int n,int start,int* nb_promotion,int schedule[6][50000]);

int rmpp_scheduling(struct task mySet[],struct task tmpSet[],struct task svgSet[],int start, int promotion, int miss,int n,int nb_promotion,int schedule[6][50000]);

int hyperPeriod (struct task mySet[], int n);

void analyse(struct task mySet[], int n);

void customSet(void);

#endif /* Rate_Mono_h */
