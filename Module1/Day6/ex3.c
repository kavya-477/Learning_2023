#include <stdio.h>

// Structure to represent a time period
struct Time {
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time t1, struct Time t2) {
    struct Time diff;

    // Convert both time periods to seconds
    int time1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the absolute difference in seconds
    int diffSeconds = time1Seconds - time2Seconds;
    if (diffSeconds < 0)
        diffSeconds = -diffSeconds;

    // Convert the difference back to hours, minutes, and seconds
    diff.hours = diffSeconds / 3600;
    diffSeconds %= 3600;
    diff.minutes = diffSeconds / 60;
    diff.seconds = diffSeconds % 60;

    return diff;
}

int main() {
    struct Time time1, time2, difference;

    // Read the first time period
    printf("Enter the first time period (hours minutes seconds): ");
    scanf("%d %d %d", &time1.hours, &time1.minutes, &time1.seconds);

    // Read the second time period
    printf("Enter the second time period (hours minutes seconds): ");
    scanf("%d %d %d", &time2.hours, &time2.minutes, &time2.seconds);

    // Calculate the difference
    difference = calculateTimeDifference(time1, time2);

    // Display the difference
    printf("Time difference: %d hours %d minutes %d seconds\n",
           difference.hours, difference.minutes, difference.seconds);

    return 0;
}
