#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>
#include "Earliest.h"


//This is for earliest deadline first
//Refrence GeeksforGeeks
void EDF(){
    
    //initial declorations
    int n;
    Job jobs[100];
    int totalBurst=0;
    
    printf("Enter Total Number of Processes: ");
    scanf("%u", &n);
    
    //Gets burst time for each process
    for (int i = 0; i < n; i++){
      jobs[i].ID = i;
      printf("Burst Time of P[%u]: ", jobs[i].ID);
      scanf("%u", &jobs[i].burst);
      jobs[i].remaining = jobs[i].burst;
      jobs[i].finished = false;
      totalBurst += jobs[i].burst;
    }
    
    //defualts arival time to 0
    for (int i=0; i<n; i++){
      jobs[i].arrival = 0;
    }
    
    //Gets deadlines
    for (int i=0; i<n; i++){
        printf("Deadline of P[%u]: ", jobs[i].ID);
        scanf("%u", &jobs[i].deadline);
    }
    
    //gets the periods
    for (int i=0; i<n; i++){
        printf("Period of P[%u]: ", jobs[i].ID);
        scanf("%u", &jobs[i].period);
    }
    clock_t start,end;
    double TimeUsed;
    start = clock();
    
    //Sets the exicution time to the burst time for each
    for(int i=0; i<n; i++){
        jobs[i].exicute = jobs[i].burst;
    }
    int help[1000];
    for(int i=0;i<n;i++){
        help[i]=jobs[i].period;
    }
    int h=0;
    int LowestHelp, LowestIndex;
    while(h==0){
        h=1;
        LowestHelp = help[0];
        LowestIndex=0;
        for(int i=0; i<n; i++){
            if(LowestHelp != help[i]){
                h=0;
                if(LowestHelp > help[i]){
                    LowestHelp = help[i];
                    LowestIndex=i;
                }
            }
        }
        if(h==0){
            help[LowestIndex] = LowestHelp + jobs[LowestIndex].period;
        }
    }
    int LCMPeriod = help[0];
    printf("LCM : %d\n",LCMPeriod);

    float Condition = 0;
    float x, y;
    printf("The Sum Of: \n");
    for(int i=0; i<n; i++){
        x=jobs[i].exicute;
        y=jobs[i].period;
        Condition+=(x/y);
        printf("%d/%d\n",jobs[i].exicute, jobs[i].period);
    }
    printf("is equal to %f\n", Condition);
    if(Condition > 1){
        printf("Scheduling is not possible\n");
        end=clock();
    }
    else{
        int EarlyDeadline, DeadlineIndex=0;
        int RemainCapacity[1000], NextDeadline[1000];
        int NewPeriod[1000];
        for(int i=0; i<n; i++){
            NextDeadline[i]= jobs[i].deadline;
            RemainCapacity[i] = jobs[i].exicute;
            NewPeriod[i] = 0;
        }
        for(int i=0;i<LCMPeriod;i++){
            EarlyDeadline = LCMPeriod;
            DeadlineIndex-=1;
            for(int j=0; j<n;j++){
                if(RemainCapacity[j] > 0){
                    if(EarlyDeadline > NextDeadline[j]){
                        EarlyDeadline = NextDeadline[j];
                        DeadlineIndex = j;
                    }
                }
            }
            printf("%d,%d: [execution %d]\n", i, i+1, DeadlineIndex);
            RemainCapacity[DeadlineIndex]--;
            for(int j=0; j<n; j++){
                if(NewPeriod[j] == (jobs[j].period -1)){
                    NextDeadline[j] = jobs[j].deadline;
                    RemainCapacity[j] = jobs[j].exicute;
                    NewPeriod[j]=0;
                }
                else{
                    if(NextDeadline[j]>0){
                        NextDeadline[j]--;
                    }
                    NewPeriod[j]++;
                }
            }
        }
        end = clock();
        TimeUsed=((double)(end-start))/CLOCKS_PER_SEC;
        printf("Average Time: %lf\n",TimeUsed);
    }
}
