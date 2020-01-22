// starting point for COMP1511 lab 11

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_STUDENT_NAME_LENGTH 128
#define MAX_GRADE_STRING_LENGTH 22
#define MAX_LAB_NAME_LENGTH 32
#define MAX_LINE_LENGTH 4096

struct student {
    int              zid;
    char             name[MAX_STUDENT_NAME_LENGTH + 1];
    char             lab_name[MAX_LAB_NAME_LENGTH + 1];
    char             lab_grades[MAX_GRADE_STRING_LENGTH + 1];
    struct student   *next;
};

struct student *read_students_file(char filename[]);
struct student *read_student(FILE *stream);

double grades2labmark(char grades[]);

int main(int argc, char *argv[]) {

    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <marks-file>\n", argv[0]);
        return 1;
    }

    struct student *student_list = read_students_file(argv[1]);
    struct student *start = student_list;
    struct student *current = start->next;
    
    if (!strcmp(start->lab_name, argv[2]))
        {
            printf("%d %-30s %-12s %-22s %4.1lf\n", start->zid, start->name, 
                start->lab_name, start->lab_grades, grades2labmark(start->lab_grades));  
        }
    
    while (current->next != NULL)
    {
        if (!strcmp(current->lab_name, argv[2]))
        {
            printf("%d %-30s %-12s %-22s %4.1lf\n", current->zid, current->name, 
                current->lab_name, current->lab_grades, grades2labmark(current->lab_grades));  
        }
        current = current->next;
    }
    
    start = student_list;
    current = start->next;
    
    while (current->next != NULL)
    {
        struct student* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}





















// DO NOT CHANGE THE CODE BELOW HERE - DO NOT CHANGE read_students_file

// read_students_file reads a file where line contains information for 1 student
// it creates a linked of student structs containing the information
// it returns a pointer to the head of the list

struct student *read_students_file(char filename[]) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr,"warning file %s could not  be opened for reading\n", filename);
        return NULL;
    }

    struct student *first_student = NULL;
    struct student *last_student = NULL;
    struct student *s;
    while ((s = read_student(fp)) != NULL) {
        if (last_student == NULL) {
            first_student = s;
            last_student = s;
        } else {
            last_student->next = s;
            last_student = s;
        }
    }

    fclose(fp);
    return first_student;
}

// DO NOT CHANGE read_student

// read_student mallocs a student struct
// and reads a line in this format:
//
// 5099703 Tsun Bordignon thu13-sitar A+A+CABAB..A.
//
// stores the values in the struct field
// and returns a pointer to the struct

struct student *read_student(FILE *stream) {
    char line[MAX_LINE_LENGTH];

    struct student *s = malloc(sizeof (struct student));
    assert(s);

    if (fgets(line, MAX_LINE_LENGTH, stream) == NULL) {
        free(s);
        return NULL;
    }

    char *newline_ptr = strchr(line, '\n');
    assert(newline_ptr);
    *newline_ptr = '\0';

    char *space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_grades, space_ptr + 1, MAX_GRADE_STRING_LENGTH);
    s->lab_grades[MAX_GRADE_STRING_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strrchr(line, ' ');
    assert(space_ptr);
    strncpy(s->lab_name, space_ptr + 1, MAX_LAB_NAME_LENGTH);
    s->lab_name[MAX_LAB_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    space_ptr = strchr(line, ' ');
    assert(space_ptr);
    strncpy(s->name, space_ptr + 1, MAX_STUDENT_NAME_LENGTH);
    s->name[MAX_STUDENT_NAME_LENGTH] = '\0';
    *space_ptr = '\0';

    s->zid = atoi(line);
    s->next = NULL;
    return s;
}

double grades2labmark(char grades[])
{
    double grade = 0;
    int i = 0;
    
    while (grades[i] != '\0')
    {
        if (grades[i] == 'C')
        {
            grade = grade + 0.5;
        } 
        
        else if (grades[i] == 'B')
        {
            grade = grade + 0.8;
        }   
        
        else if (grades[i] == 'A')
        {
            
            if (grades[i+1] == '+')
            {
                grade = grade + 1.2;
                i++;
            }
        
            else
            {
                grade = grade + 1;
            }
        } 
        i++;   
    }
    if (grade > 10) 
    {
        return 10;
    }
    return grade;
}
