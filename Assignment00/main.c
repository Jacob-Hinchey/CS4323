//Auther Name: Jacob Hinchey
//Email: jacob.hinchey@okstate.edu
//Data: 2/11/2020
//Program Description: Takes in a prdeturmined sized array of student structs and stores them into a database structure
//The database points to each student to print them after the user is finished, then it deletes the database and exits

#include <stdio.h>
#include "student_record.h"

//main function which calls all of the functions declared in student_record.h
int main(){
    Database* student_data = create_database();
    print_database(student_data);
    destroy_database(student_data);
    return 0;
}
