#include <stdio.h>

// Structure to represent a complex number
struct Complex {
    double real;
    double imaginary;
};

// Function to read a complex number from the user
void readComplex(struct Complex* c) {
    printf("Enter the real part: ");
    scanf("%lf", &(c->real));

    printf("Enter the imaginary part: ");
    scanf("%lf", &(c->imaginary));
}

// Function to write a complex number to the console
void writeComplex(struct Complex c) {
    if (c.imaginary >= 0)
        printf("Complex number: %.2f + %.2fi\n", c.real, c.imaginary);
    else
        printf("Complex number: %.2f - %.2fi\n", c.real, -c.imaginary);
}

// Function to add two complex numbers
struct Complex addComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imaginary = c1.imaginary + c2.imaginary;
    return result;
}

// Function to multiply two complex numbers
struct Complex multiplyComplex(struct Complex c1, struct Complex c2) {
    struct Complex result;
    result.real = c1.real * c2.real - c1.imaginary * c2.imaginary;
    result.imaginary = c1.real * c2.imaginary + c1.imaginary * c2.real;
    return result;
}

int main() {
    struct Complex num1, num2, sum, product;

    printf("Reading the first complex number:\n");
    readComplex(&num1);

    printf("\nReading the second complex number:\n");
    readComplex(&num2);

    printf("\nPerforming operations:\n");

    printf("\nWriting the first complex number:\n");
    writeComplex(num1);

    printf("\nWriting the second complex number:\n");
    writeComplex(num2);

    // Addition
    sum = addComplex(num1, num2);
    printf("\nSum of the complex numbers:\n");
    writeComplex(sum);

    // Multiplication
    product = multiplyComplex(num1, num2);
    printf("\nProduct of the complex numbers:\n");
    writeComplex(product);

    return 0;
}
