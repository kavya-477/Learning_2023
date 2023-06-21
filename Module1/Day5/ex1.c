#include <stdio.h>

struct Box {
    double length;
    double width;
    double height;
};

int main() {
    struct Box myBox = { 10.0, 5.0, 7.5 };
    struct Box* ptrBox = &myBox;

    // Calculate volume using the pointer with (*) asterisk and (.) dot operator
    double volume = (*ptrBox).length * (*ptrBox).width * (*ptrBox).height;
    printf("Volume: %.2f\n", volume);

    // Calculate total surface area using the pointer with (*) asterisk and (.) dot operator
    double surfaceArea = 2 * ((*ptrBox).length * (*ptrBox).width +
                             (*ptrBox).length * (*ptrBox).height +
                             (*ptrBox).width * (*ptrBox).height);
    printf("Total Surface Area: %.2f\n", surfaceArea);

    // Calculate volume using the pointer with (->) arrow operator (dot representation)
    volume = ptrBox->length * ptrBox->width * ptrBox->height;
    printf("Volume: %.2f\n", volume);

    // Calculate total surface area using the pointer with (->) arrow operator (dot representation)
    surfaceArea = 2 * (ptrBox->length * ptrBox->width +
                       ptrBox->length * ptrBox->height +
                       ptrBox->width * ptrBox->height);
    printf("Total Surface Area: %.2f\n", surfaceArea);

    return 0;
}
