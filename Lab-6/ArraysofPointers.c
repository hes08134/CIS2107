/* 
Name: Eunseo Hwang
Date: Feb 22 2026
Course: CIS2107 
HW#: Lab 06: “Arrays of Pointers to Functions” 

Objective: To design and implement array of function pointer. 

The purpose of this program is to modify existing code related to examslecting 
grades for individual students in a 2D matrix and determining the minimum, maximum, and each average. 

// Each of the functions has also been modified to allow for a
// menu-driven interface. This interface is an array of pointers to the functions.

*/

#include <stdio.h>
#include <stdlib.h>
void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main()
{
    int choice;
    int students;
    int exams;

    puts("Creating 2D Array of student grades: \n");
    printf("How many students (rows)? ");
    scanf("%d", &students);
    printf("How many test grades (columns)? ");
    scanf("%d", &exams);

    int grades[students][exams];

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++){
            printf("Enter [%d][%d]: ", i, j);
            scanf("%d", &grades[i][j]);
        }
    }
    puts("");

    void (*processGrades[4])(int students, int exams, int a[][exams]) = {
            printArray, minimum, maximum, average
        };

    do {
        printf("Enter a choice: \n");
        printf("\t0 Print the array of grades\n");
        printf("\t1 Find the minimum grade\n");
        printf("\t2 Find the maximum grades\n");
        printf("\t3 Print the average on all tests for each student\n");
        printf("\t4 End program\n");

        scanf("%d", &choice);
        puts("");

        if (choice >= 0 && choice <= 3) {
            processGrades[choice](students, exams, grades);
        } else if (choice != 4) {
            printf("Invalid choice");
        }
    } while (choice != 4);
}

void printArray(int students, int exams, int grades[students][exams]){
    puts("This array is: \n");

    printf("%13s", " ");
    for (int j = 0; j < exams; j++) {
        printf("[%d]  ", j);
    }
    puts("");

    for (int i = 0; i < students; i++) {
        printf("Student [%d]", i);
        for (int j = 0; j < exams; j++) {
            printf("%5d", grades[i][j]);
        }
        puts("");
    }
    puts("");
}

void minimum(int students, int exams, int grades[students][exams]){
    int lowest = grades[0][0];

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (grades[i][j] < lowest) {
                lowest = grades[i][j];
            }
        }
    }
    printf("Lowest exam grade: %d\n\n", lowest);
}

void maximum(int students, int exams, int grades[students][exams]){
    int highest = grades[0][0];

    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (highest < grades[i][j]) {
                highest = grades[i][j];
            }
        }
    }
    printf("Highest exam grade: %d\n\n", highest);
}

void average(int students, int exams, int grades[students][exams]){
    for (int i = 0; i < students; i++) {
        double sum = 0;
        for (int j = 0; j < exams; j++) {
            sum += grades[i][j];
        }
        printf("The average for student %d is %.2f\n", i, sum / exams);
    }
    puts("");
}
