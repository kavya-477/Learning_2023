#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[20];
    float marks;
};

void parseString(char* input, struct Student* students, int numStudents) {
    char* token = strtok(input, " ");
    int i = 0;

    while (token != NULL && i < numStudents) {
        sscanf(token, "%d", &(students[i].rollno));
        token = strtok(NULL, " ");

        strncpy(students[i].name, token, sizeof(students[i].name) - 1);
        students[i].name[sizeof(students[i].name) - 1] = '\0';
        token = strtok(NULL, " ");

        sscanf(token, "%f", &(students[i].marks));
        token = strtok(NULL, " ");

        i++;
    }
}

int main() {
    char input[100];
    printf("Enter the input string: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';  // Remove newline character

    int numStudents = 0;
    printf("Enter the number of students: ");
    scanf("%d", &numStudents);
    getchar();  // Consume newline character

    struct Student* students = (struct Student*)malloc(numStudents * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed.\n");
        return 1;  // Exit the program with an error status
    }

    parseString(input, students, numStudents);

    printf("\nParsed student data:\n");
    for (int i = 0; i < numStudents; i++) {
        printf("Student %d:\n", i + 1);
        printf("Roll No.: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("\n");
    }

    free(students);

    return 0;
}
