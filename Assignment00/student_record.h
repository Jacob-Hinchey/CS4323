#ifndef __STUDENT_RECORD_H__
#define __STUDENT_RECORD_H__

//student struct to hold info
struct Student{
  char fullName[50];
  char address[50];
  char dateOfBirth[20];
  char eMail[40];
  char phoneNumber[20];
};
typedef struct Student Student;

//holds a pointer to an array of students and the number of students
struct Database{
  struct Student *ptr;
  int stuNumber;
};
typedef struct Database Database;

/* Function declarations. Do not modify! Implement those functions in student_record.c */
void print_student(const Student* student);
void print_database(const Database* student_record);

Database* create_database(void);
void destroy_database(Database* student_record);

#endif /* __STUDENT_RECORD_H__ */
