#include <stdio.h>

// Structure to represent a person
struct Person {
    char name[50];
    int age;
};

// Function to swap the fields of two structures using pointers
void swapStructures(struct Person* p1, struct Person* p2) {
    // Swap the name field
    char tempName[50];
    strcpy(tempName, p1->name);
    strcpy(p1->name, p2->name);
    strcpy(p2->name, tempName);

    // Swap the age field
    int tempAge = p1->age;
    p1->age = p2->age;
    p2->age = tempAge;
}

int main() {
    struct Person person1 = { "John", 25 };
    struct Person person2 = { "Alice", 30 };

    printf("Before swapping:\n");
    printf("Person 1: Name - %s, Age - %d\n", person1.name, person1.age);
    printf("Person 2: Name - %s, Age - %d\n", person2.name, person2.age);

    // Swap the structures using the swapStructures function
    swapStructures(&person1, &person2);

    printf("\nAfter swapping:\n");
    printf("Person 1: Name - %s, Age - %d\n", person1.name, person1.age);
    printf("Person 2: Name - %s, Age - %d\n", person2.name, person2.age);

    return 0;
}
