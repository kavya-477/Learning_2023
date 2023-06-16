#include <stdio.h>

int findLargestAfterDeletingDigit(int number) {
    int largest = 0;
    int temp = number;

    // Iterate through each digit
    for (int i = 0; i < 4; i++) {
        int divisor = 1;
        int digit;

        // Remove one digit
        for (int j = 0; j < 4; j++) {
            if (j != i) {
                digit = temp / divisor % 10;
                divisor *= 10;
                largest = largest * 10 + digit;
            }
        }

        // Reset the temporary variable
        temp = number;
    }

    return largest;
}

int main() {
    int number;

    printf("Enter a 4-digit number: ");
    scanf("%d", &number);

    int largestNumber = findLargestAfterDeletingDigit(number);
    printf("Largest number after deleting a single digit: %d\n", largestNumber);

    return 0;
}
