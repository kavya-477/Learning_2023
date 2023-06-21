#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_STUDENTS 100

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    char grade;
} Student;

void searchStudentsByName(Student students[], int numStudents, const char* name) {
    int i;
    int found = 0;

    for (i = 0; i < numStudents; i++) {
        if (strcmp(students[i].name, name) == 0) {
            printf("Name: %s, Age: %d, Grade: %c\n", students[i].name, students[i].age, students[i].grade);
            found = 1;
        }
    }

    if (!found) {
        printf("No student found with the name '%s'\n", name);
    }
}

int main() {
    Student students[MAX_STUDENTS] = {
        {"Alice", 18, 'A'},
        {"Bob", 17, 'B'},
        {"Charlie", 19, 'A'},
        {"Alice", 20, 'B'}
    };

    int numStudents = 4;
    const char* searchName = "Alice";

    searchStudentsByName(students, numStudents, searchName);

    return 0;
}
