#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "Rate-Mono.h"

//Rate-monotonic schdeuling
//Refrence GeeksforGeeks
int RMS (void){
    srand(time(NULL));
    customSet();
    return 0;
}

//Used to get user data for processes
void customSet(){
    int n;

    printf("Enter total number of process: ");
    scanf("%d",&n);

    struct task mySet[n];

    for(int i=0;i<n;i++){
        printf("Exicution Time of P[%d]: ",i);
        scanf("%d",&mySet[i].executionTime);
        printf("Period: ");
        scanf("%d",&mySet[i].period);
        mySet[i].executing=0;
        mySet[i].occurence=0;
        mySet[i].utilisation=(float)mySet[i].executionTime/mySet[i].period;

    }

     for(int i=1;i<n;i++){
            for(int j=0;j<n-1;j++){
                if(mySet[i].period<mySet[j].period){
                    struct task tmp=mySet[i];
                    mySet[i]=mySet[j];
                    mySet[j]=tmp;
                }
            }
    }

    for(int i=0;i<n;i++){
        mySet[i].priority=n-i;
    }

    analyse(mySet,n);
}


//Checks to ensure the processes are valid for RMS
void analyse(struct task mySet[], int n){
    int promotion,nb_promotion=0;
    int start=0;
    int y=1;

    struct task tmpSet[n];
    struct task svgSet[n];
    for(int i=0;i<n;i++){
        tmpSet[i]=mySet[i];
        svgSet[i]=mySet[i];
    }

    int schedule[6][50000];

    int miss=rm_scheduling(mySet,tmpSet,svgSet,n,start,&nb_promotion,schedule);

    //If it does not miss any, then is successes
    if(miss==0){
        //Placeholders
        printf("This is possible for Rate-Monotonic");
        printf("\nAverage Waiting Time: 1.66");
        printf("\nAverage Completion Time: 2.00");
    }
    else{
        printf("\nThis is not possible for Rate-Monotonic\n");
        for(int i=0;i<n;i++){
            mySet[i].occurence=0;
            mySet[i].executing=0;
        }
    }

    while(miss!=0){
        promotion=miss;
        while(promotion!=start&&y==1){
            promotion--;
            for(int i=0;i<n;i++){
                tmpSet[i]=mySet[i];
            }
            y=rmpp_scheduling(mySet,tmpSet,svgSet,start,promotion,miss,n,nb_promotion,schedule);
        }
        if(y==0){
            nb_promotion=0;
            start=miss+1;
            miss=0;
            miss=rm_scheduling(mySet,tmpSet,svgSet,n,start,&nb_promotion,schedule);
            if(miss!=0){
                y=1;
            }
        }
        else{
            printf("\nThis is not possible for Rate-Monotonic\n");
            break;
        }
    }
}


int hyperPeriod (struct task mySet[], int n){

    int x=0,i,j=0,c;

    while(x==0){
        j++;
        c=0;
        for(i=0;i<n;i++){
            if(j%mySet[i].period==0){
                c++;
            }
        }
        if(c==n){
            x=j;
        }
    }
    return x;

}

//Assists in miss checking

int rm_scheduling(struct task mySet[],struct task tmpSet[],struct task svgSet[], int n,int start,int* nb_promotion,int schedule[6][50000]){

    int miss=0;
    int c=0;

    int ex;
    int t=0;
    int hyp=hyperPeriod(svgSet,n);
    for(t=start;t<hyp;t++){

        for(int i=0;i<n;i++){
            if(t%svgSet[i].period==0){
                tmpSet[i].executing=1;
                if(tmpSet[i].executionTime!=0&&t!=0){
                    c++;
                }
                if(c!=0){
                    *nb_promotion=c;
                    return t;
                }
                else tmpSet[i].executionTime=svgSet[i].executionTime;
            }
        }

        ex=-1;
        int highest=-1;
        for(int i=0;i<n;i++){
            if(tmpSet[i].executing==1){
                highest=i;
                break;
            }
        }
        for(int i=1;i<n;i++){
            if(tmpSet[i].executing&&(tmpSet[i].priority>tmpSet[highest].priority)){
                highest=i;
            }
        }
        ex=highest;

        if(t<50000){
        schedule[0][t]=0;
        schedule[1][t]=t;
        schedule[2][t]=ex;
        schedule[3][t]=tmpSet[ex].occurence+1;
        schedule[4][t]=tmpSet[ex].period*(tmpSet[ex].occurence+1);
        schedule[5][t]=tmpSet[ex].executionTime-1;}

        if(ex!=-1){
            if(tmpSet[ex].executionTime>0){
                tmpSet[ex].executionTime=tmpSet[ex].executionTime-1;

            }
            if(tmpSet[ex].executionTime==0){
                tmpSet[ex].occurence++;
                tmpSet[ex].executing=0;
            }
        }
    }
    return miss;
}

//Assists in miss checking
int rmpp_scheduling(struct task mySet[],struct task tmpSet[],struct task svgSet[],int start, int promotion, int miss,int n,int nb_promotion,int schedule[6][50000]){
    int ex;
    int t=0;
    for(t=start;t<=miss;t++){
        for(int i=0;i<n;i++){
            if(t%svgSet[i].period==0){
                tmpSet[i].executing=1;
                if(tmpSet[i].executionTime!=0&&t!=0){
                    return 1;
                }
                else{
                    tmpSet[i].executionTime=svgSet[i].executionTime;
                }
            }
        }

        if(t==promotion){
            for(int i=n-1;i>=n-nb_promotion;i--){
                tmpSet[i].priority=50;
                for(int j=0;j<n;j++){
                    if(tmpSet[j].period==tmpSet[i].period){
                        tmpSet[j].priority=50;
                    }
                }
            }
        }
        if(t==miss){
            for(int i=0;i<n;i++){
                tmpSet[i].priority=svgSet[i].priority;
            }
        }


        ex=-1;
        int highest=-1;
        for(int i=0;i<n;i++){
            if(tmpSet[i].executing==1){
                highest=i;
                break;
            }
        }
        for(int i=1;i<n;i++){
            if(tmpSet[i].executing&&(tmpSet[i].priority>tmpSet[highest].priority)){
                highest=i;
            }
        }
        ex=highest;

    if(t<50000){
        if(tmpSet[ex].priority==50){
            schedule[0][t]=1;
        }
        else{
            schedule[0][t]=0;
        }
        schedule[1][t]=t;
        schedule[2][t]=ex;
        schedule[3][t]=tmpSet[ex].occurence+1;
        schedule[4][t]=tmpSet[ex].period*(tmpSet[ex].occurence+1);
        schedule[5][t]=tmpSet[ex].executionTime-1;
    }


        if(ex!=-1){
            if(tmpSet[ex].executionTime>0){
                tmpSet[ex].executionTime=tmpSet[ex].executionTime-1;

            }
            if(tmpSet[ex].executionTime==0){
                tmpSet[ex].priority=svgSet[ex].priority;
                tmpSet[ex].occurence++;
                tmpSet[ex].executing=0;
            }
        }
    }

    for(int i=0;i<n;i++){
        mySet[i]=tmpSet[i];
    }
    return 0;

}
