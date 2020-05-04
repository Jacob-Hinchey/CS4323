//
//  Earliest.h
//  Assignment_04
//
//  Created by Jacob HInchey on 4/25/20.
//  Copyright © 2020 Jacob Hinchey. All rights reserved.
//

#ifndef Earliest_h
#define Earliest_h

#include <stdio.h>
typedef struct{
    int ID;
    unsigned int arrival;
    unsigned int prior;
    unsigned int burst;
    unsigned int remaining;
    int exicute, deadline, period;
    int wait, complete;
    bool finished;
}Job;
#endif /* Earliest_h */
