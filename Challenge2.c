#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct my_date_t {
    uint8_t date;
    uint8_t month;
    uint16_t year;
} my_date_t;

typedef enum status_t {
    SUCCESS,
    NULL_PTR,
    INCORRECT
} status_t;

status_t string_to_date_converter(char* input_string, my_date_t* result_date) {
    if (input_string == NULL || result_date == NULL) {
        return NULL_PTR;
    }
    
    // Check string length
    size_t len = strlen(input_string);
    if (len != 10) {
        return INCORRECT;
    }
    
    // Check separator positions
    if (input_string[2] != '/' || input_string[5] != '/') {
        return INCORRECT;
    }
    
    // Extract day, month, and year
    char* token = strtok(input_string, "/");
    if (token == NULL) {
        return INCORRECT;
    }
    int day = atoi(token);
    
    token = strtok(NULL, "/");
    if (token == NULL) {
        return INCORRECT;
    }
    int month = atoi(token);
    
    token = strtok(NULL, "/");
    if (token == NULL) {
        return INCORRECT;
    }
    int year = atoi(token);
    
    // Check validity of day, month, and year values
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 0) {
        return INCORRECT;
    }
    
    // Assign values to result_date structure
    result_date->date = (uint8_t)day;
    result_date->month = (uint8_t)month;
    result_date->year = (uint16_t)year;
    
    return SUCCESS;
}

int main() {
    char date_string[] = "25/06/2023";
    my_date_t result_date;
    
    status_t status = string_to_date_converter(date_string, &result_date);
    if (status == SUCCESS) {
        printf("Conversion successful\n");
        printf("Day: %u\n", result_date.date);
        printf("Month: %u\n", result_date.month);
        printf("Year: %u\n", result_date.year);
    } else {
        printf("Conversion error: ");
        if (status == NULL_PTR) {
            printf("NULL pointers\n");
        } else if (status == INCORRECT) {
            printf("Incorrect values for date or month or year\n");
        }
    }
    
    return 0;
}


