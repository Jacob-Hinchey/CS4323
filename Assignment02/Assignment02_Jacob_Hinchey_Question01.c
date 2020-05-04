//Name: Jacob Hinchey
//EMail: Jacob.hinchey@okstate.edu
//Date: 03/13/2020
//Description: This program reads in a user input of a movie then takes it to find information
//about the movie from 4 different csv files. THis is done using both threads and
//no threads to compare
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "Assignment02_Jacob_Hinchey_Question01.h"


//variable definitions
int row_count = 62424;
int found_id, flag = 0;
char genre[1000];
FILE *movies;
FILE *tags;
FILE *ratings;
FILE *links;
int counter=0;
float avg_rating;
double imbdID;


//structs to hold csv





void *search_movie(char title_year){
   counter+=1;
   movies = fopen("movie.csv", "r");
   struct movie row;
   //searches first half of file
   if ((counter-1) == 0){
       //for each row
       for (int cnt=0; cnt < row_count/2; cnt++){
           fread(&row, sizeof(struct movie), 1, movies);
           if (strcmp(row.title, &title_year) && flag==0){
               found_id = row.mov_id;
               strcpy(genre, row.genre);
               flag=1;
           }
           else if (flag==1) break; //break the loop if the movie is already found
       }
   }
   //searched second have of file
   else if ((counter-1) == 1){
       for (int cnt= row_count/2; cnt <= row_count; cnt++){
           fread(&row, sizeof(struct movie), 1, movies);
           if (strcmp(row.title, &title_year) && flag==0){
               found_id = row.mov_id;
               strcpy(genre, row.genre);
               flag=1;
           }
           else if (flag==1) break;
       }
   }
    fclose(movies);
}

void *search_rating(int id){
   ratings = fopen("ratings.csv", "r");
   struct rating row;
   int count=0;
   float total_rating=0;
   while(fread(&row, sizeof(struct rating), 1, ratings)){
       if (row.mov_id == found_id){
           count+=1;
           total_rating+=row.user_rating;
       }
   }
   avg_rating = total_rating/count;
   fclose(ratings);
}

char user_tags[10000]; //global variable for the user tags
void *search_tag(int id){
   tags = fopen("tag.csv", "r");
   struct tag row;
   while(fread(&row, sizeof(struct tag), 1, tags)){
       if (row.mov_id == found_id){
           //creates string of a tags
           strcpy(user_tags, strcat(user_tags, ",")); 
           strcpy(user_tags, strcat(user_tags, row.tag));
           
       }
   }
    fclose(tags);
}

void *search_link(int id){
   links = fopen("links.csv", "r");
   struct link row;
   while(fread(&row, sizeof(struct link), 1, links)){
       if (row.mov_id == found_id){
           imbdID = row.imbdid;
           break;
       }
   }
   fclose(links);
}


int main(){
//   movies = fopen("movie.csv", "r");
//    //char *ptr;
//
//    char buffer[1000][1000];
//    char buffer2[1000][1000];
//    char buffer1[1000][1000];
//    printf("fdsaf\n");
//    int i =0;
//    while(fscanf(movies, "%s,%s,%s", buffer[i],buffer2[i],buffer1[i])!= EOF){
//        printf("%s",buffer[0]);
//        i++;
//    }
//    printf("%s\n",buffer);
//    printf("%s\n",buffer2);
//    printf("%s\n",buffer1);
//    sleep(5);
//    fgets(buffer,100, movies);
//    int i =0;
//    while(buffer != NULL){
//
//        printf("%s, ')
//        i++;
//    }
   
    //initialize threads
   pthread_t search_thread[2];
   pthread_t retrieve_thread[3];
   
   //get the input from the user
   char user_input[10000];
   printf("Enter the movie title and year in the following format : Title (Year)");
   scanf("%s", user_input);

    movies = fopen("movie.csv", "r");
    
   //two treads to search movies
   for (int i=0; i < 2; i++) pthread_create(&search_thread[i], NULL, search_movie, user_input);

   for (int i = 0; i < 2; i++) pthread_join(search_thread[i], NULL);

   //check if it was found
   if (flag==0){
       printf("Movie Title not found");
   }
   else{
       //find other info
       pthread_create(&retrieve_thread[0], NULL, search_tag, found_id);
       pthread_create(&retrieve_thread[1], NULL, search_link, found_id);
       pthread_create(&retrieve_thread[2], NULL, search_rating, found_id);

       for (int i = 0; i < 3; i++) pthread_join(retrieve_thread[i], NULL);

       printf("Genre: %s \n", genre);
       printf("Average rating: %f \n", avg_rating);
       printf("Movie tags: %s \n", user_tags);
       printf("IMBD ID: %f \n", imbdID);
   }
    return 0;
}
