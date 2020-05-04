//
//  Assignment02_Jacob_Hinchey_Question01.h
//  Assignment02_Jacob_Hinchey_Questtion01
//
//  Created by Jacob HInchey on 3/4/20.
//  Copyright © 2020 Jacob Hinchey. All rights reserved.
//

#ifndef Assignment02_Jacob_Hinchey_Question01_h
#define Assignment02_Jacob_Hinchey_Question01_h


#include <stdio.h>
FILE *movies;
FILE *tags;
FILE *ratings;
FILE *links;

struct movie{
   int mov_id;
   char title[10000];
   char genre[1000];
};

struct rating{
   int user_id;
   int mov_id;
   float user_rating;
};

struct tag{
   int user_id;
   int mov_id;
   char tag[10000];
};

struct link{
   int mov_id;
   double imbdid;
};


#endif /* Assignment02_Jacob_Hinchey_Question01_h */
