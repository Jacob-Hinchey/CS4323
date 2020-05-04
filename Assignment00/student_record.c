#include <stdio.h>
#include <stdlib.h>
#include "student_record.h"

//Takes a pointer to an array of students and prints each variable with description
void print_student(const struct Student* student){
    printf("Name: %s", student->fullName);
    printf("Address: %s", student->address);
    printf("Date of Birth: %s", student->dateOfBirth);
    printf("eMail: %s", student->eMail);
    printf("Phone Number: %s\n", student->phoneNumber);
}

//Takes a database pointer and iterates through each student in it calling the print_student function
void print_database(const Database* student_record){
    printf("\nThis is the student record database:\n\n");
    for(int i = 0; i < student_record->stuNumber; i++){
        printf("Student %d\n", i+1);
        print_student(&student_record->ptr[i]);
    }
}

//creates a database for students
Database* create_database(void){
    Database* mainData = (Database*) malloc(sizeof(Database));
    
    //see how many students the user wants to add and assign it to stuNumber
    printf("How many students fill the database hold? ");
    char holder[10];
    fgets(holder, 10, stdin);
    mainData->stuNumber = atoi(holder);
    
    //Allocate memory for student array
    mainData->ptr = (Student*) malloc(mainData->stuNumber*sizeof(Student));
    
    //for each student the user wants to enter, ask them for the details
    for (int i = 0; i < mainData->stuNumber; i++){
        printf("Student %d details:\n", i+1);
        printf("Enter a student name: ");
        fgets(mainData->ptr[i].fullName, 50, stdin);
        printf("Enter a student address: ");
        fgets(mainData->ptr[i].address, 50, stdin);
        printf("Enter a student date of birth(mm/dd/yyyy): ");
        fgets(mainData->ptr[i].dateOfBirth, 20, stdin);
        printf("Enter a student email: ");
        fgets(mainData->ptr[i].eMail,40, stdin);
        printf("Enter a student phone number: ");
        fgets(mainData->ptr[i].phoneNumber,20, stdin);
    }
    return mainData;
}

//takes a pointer to a database and frees the memory previously allocated
void destroy_database(Database* student_record){
    free(student_record);
}
