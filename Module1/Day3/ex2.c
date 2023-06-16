#include <stdio.h>

void print_bits(unsigned int num) {
    for (int i = 31; i >= 0; i--) {
        unsigned int mask = 1 << i;
        unsigned int bit = (num & mask) >> i;
        printf("%u", bit);
    }
    printf("\n");
}

int main() {
    unsigned int number;

    printf("Enter a 32-bit integer: ");
    scanf("%u", &number);

    printf("Binary representation: ");
    print_bits(number);

    return 0;
}
