#include <stdio.h>
#include "student_records.h"

int main()
{
    int choice;

    printf("========================================\n");
    printf(" DATABASE CLIENT-SERVER MANAGEMENT SYSTEM\n");
    printf("========================================\n");

    do
    {
        printf("\n1. Add Student");
        printf("\n2. View Students");
        printf("\n3. Update Student");
        printf("\n4. Delete Student");
        printf("\n5. Exit");

        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                add_student();
                break;

            case 2:
                view_students();
                break;

            case 3:
                update_student();
                break;

            case 4:
                delete_student();
                break;

            case 5:
                printf("\nProgram closed.\n");
                break;

            default:
                printf("\nInvalid choice!\n");
        }

    } while(choice != 5);

    return 0;
}
