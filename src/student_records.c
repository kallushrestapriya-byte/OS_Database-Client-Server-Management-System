#include <stdio.h>
#include <string.h>
#include "student_records.h"

void add_student()
{
    int id;
    char name[50];
    char course[50];
    FILE *fp;

    printf("\nEnter Student ID: ");
    scanf("%d", &id);

    printf("Enter Student Name: ");
    scanf("%s", name);

    printf("Enter Course: ");
    scanf("%s", course);

    fp = fopen("students.txt", "a");

    if (fp == NULL)
    {
        printf("Error opening database!\n");
        return;
    }

    fprintf(fp, "%d %s %s\n", id, name, course);
    fclose(fp);

    printf("Student added successfully!\n");
}

void view_students()
{
    int id;
    char name[50];
    char course[50];
    FILE *fp;

    fp = fopen("students.txt", "r");

    if (fp == NULL)
    {
        printf("\nNo student records found.\n");
        return;
    }

    printf("\nID\tName\tCourse\n");
    printf("-------------------------\n");

    while (fscanf(fp, "%d %s %s", &id, name, course) == 3)
    {
        printf("%d\t%s\t%s\n", id, name, course);
    }

    fclose(fp);
}

void update_student()
{
    int id, found = 0;
    int sid;
    char name[50], course[50];
    char new_name[50], new_course[50];
    FILE *fp, *temp;

    printf("\nEnter Student ID to update: ");
    scanf("%d", &id);

    printf("Enter new Name: ");
    scanf("%s", new_name);

    printf("Enter new Course: ");
    scanf("%s", new_course);

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Database error!\n");
        return;
    }

    while (fscanf(fp, "%d %s %s", &sid, name, course) == 3)
    {
        if (sid == id)
        {
            fprintf(temp, "%d %s %s\n", id, new_name, new_course);
            found = 1;
        }
        else
        {
            fprintf(temp, "%d %s %s\n", sid, name, course);
        }
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student updated successfully!\n");
    else
        printf("Student not found!\n");
}

void delete_student()
{
    int id, sid, found = 0;
    char name[50], course[50];
    FILE *fp, *temp;

    printf("\nEnter Student ID to delete: ");
    scanf("%d", &id);

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    if (fp == NULL || temp == NULL)
    {
        printf("Database error!\n");
        return;
    }

    while (fscanf(fp, "%d %s %s", &sid, name, course) == 3)
    {
        if (sid == id)
        {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %s\n", sid, name, course);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if (found)
        printf("Student deleted successfully!\n");
    else
        printf("Student not found!\n");
}
