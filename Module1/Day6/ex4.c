#include <stdio.h>
#include <stdlib.h>

// Structure to represent a student
struct Student {
    char name[50];
    int age;
    int rollNumber;
};

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Dynamically allocate memory for an array of n student structures
    struct Student* students = (struct Student*)malloc(n * sizeof(struct Student));

    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit the program with an error status
    }

    // Read data for n students
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);

        printf("Enter the name: ");
        scanf("%s", students[i].name);

        printf("Enter the age: ");
        scanf("%d", &(students[i].age));

        printf("Enter the roll number: ");
        scanf("%d", &(students[i].rollNumber));
    }

    // Display data for n students
    printf("\nData for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Roll Number: %d\n", students[i].rollNumber);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
