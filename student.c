#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for Student
struct Student {
    int roll;
    char name[50];
    float marks;
};

struct Student s;

// Function to Add Student
void addStudent() {

    FILE *fp;

    fp = fopen("students.txt", "a");

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %.2f\n", s.roll, s.name, s.marks);

    fclose(fp);

    printf("\nStudent Record Added Successfully!\n");
}

// Function to Display Students
void displayStudents() {

    FILE *fp;

    fp = fopen("students.txt", "r");

    printf("\n===== Student Records =====\n");

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {

        printf("\nRoll Number : %d", s.roll);
        printf("\nName        : %s", s.name);
        printf("\nMarks       : %.2f\n", s.marks);
    }

    fclose(fp);
}

// Function to Search Student
void searchStudent() {

    FILE *fp;

    int rollNo, found = 0;

    fp = fopen("students.txt", "r");

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &rollNo);

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {

        if(s.roll == rollNo) {

            printf("\nStudent Found!\n");

            printf("Roll Number : %d\n", s.roll);
            printf("Name        : %s\n", s.name);
            printf("Marks       : %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    if(found == 0) {
        printf("\nStudent Record Not Found!\n");
    }

    fclose(fp);
}

// Function to Delete Student
void deleteStudent() {

    FILE *fp, *temp;

    int rollNo, found = 0;

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("\nEnter Roll Number to Delete: ");
    scanf("%d", &rollNo);

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {

        if(s.roll == rollNo) {

            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found == 1) {
        printf("\nStudent Record Deleted Successfully!\n");
    } else {
        printf("\nStudent Record Not Found!\n");
    }
}

// Function to Update Student
void updateStudent() {

    FILE *fp, *temp;

    int rollNo, found = 0;

    fp = fopen("students.txt", "r");
    temp = fopen("temp.txt", "w");

    printf("\nEnter Roll Number to Update: ");
    scanf("%d", &rollNo);

    while(fscanf(fp, "%d %s %f", &s.roll, s.name, &s.marks) != EOF) {

        if(s.roll == rollNo) {

            found = 1;

            printf("\nEnter New Name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter New Marks: ");
            scanf("%f", &s.marks);
        }

        fprintf(temp, "%d %s %.2f\n", s.roll, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("students.txt");
    rename("temp.txt", "students.txt");

    if(found == 1) {
        printf("\nStudent Record Updated Successfully!\n");
    } else {
        printf("\nStudent Record Not Found!\n");
    }
}

int main() {

    int choice;

    do {

        printf("\n===== Student Management System =====\n");

        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Update Student\n");
        printf("6. Exit\n");

        printf("Enter Your Choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                updateStudent();
                break;

            case 6:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    printf("\nThank You!\n");

    return 0;
}