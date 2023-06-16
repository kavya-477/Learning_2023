#include <stdio.h>

int bit_operations(int num, int oper_type) {
    int result = num;  // Initialize result with the input number

    switch (oper_type) {
        case 1:
            result |= (1 << 0);  // Set the 1st bit
            break;
        case 2:
            result &= ~(1 << 31);  // Clear the 31st bit
            break;
        case 3:
            result ^= (1 << 15);  // Toggle the 16th bit
            break;
        default:
            printf("Error: Invalid operation type.\n");
            break;
    }

    return result;
}

int main() {
    int number, operationType;

    printf("Enter a 32-bit integer: ");
    scanf("%d", &number);

    printf("Enter the operation type (1 for Set, 2 for Clear, 3 for Toggle): ");
    scanf("%d", &operationType);

    int result = bit_operations(number, operationType);
    printf("Result: %d\n", result);

    return 0;
}
