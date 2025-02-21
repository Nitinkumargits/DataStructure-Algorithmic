// C program to declare and use dynamic array of structure

#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a student
struct Student
{
    char name[50];
    int age;
};

int main()
{

    // Declaring a pointer to a structure and allocating
    // memory for initial (3) students
    struct Student *students = (struct Student *)malloc(3 * sizeof(*students));

    // Check for malloc Failure
    if (students == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Providing some sample data for the students
    for (int i = 0; i < 3; i++)
    {
        snprintf(students[i].name, sizeof(students[i].name),
                 "Student%d", i + 1);
        students[i].age = 20 + i;
    }

    // Displaying the student data
    printf("Student Data:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("Student %d: Name - %s, Age - %d\n", i + 1,
               students[i].name, students[i].age);
    }

    // free the memory when done
    free(students);
    return 0;
}
