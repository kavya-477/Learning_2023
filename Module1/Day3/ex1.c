#include <stdio.h>

void print_numbers(int n) {
    for (int i = 1; i <= n; i++) {
        printf("%d", i);
    }
    for (int i = n - 1; i >= 1; i--) {
        printf("%d", i);
    }
}

void print_spaces(int n) {
    for (int i = 1; i <= n; i++) {
        printf(" ");
    }
}

void print_pattern(int n) {
    for (int i = n; i >= 1; i--) {
        print_numbers(i);
        print_spaces((n - i) * 2);
        print_numbers(i);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    print_pattern(n);

    return 0;
}
