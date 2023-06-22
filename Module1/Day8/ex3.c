#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 256

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char time[9];
} LogEntry;

LogEntry logEntries[MAX_ENTRIES];
int numEntries = 0;

void readDataFromFile() {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open data.csv.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    fgets(line, sizeof(line), file); // Skip the header line

    while (fgets(line, sizeof(line), file) != NULL && numEntries < MAX_ENTRIES) {
        char *token;
        int tokenCount = 0;

        token = strtok(line, ",");
        while (token != NULL) {
            switch (tokenCount) {
                case 0:
                    logEntries[numEntries].entryNo = atoi(token);
                    break;
                case 1:
                    strcpy(logEntries[numEntries].sensorNo, token);
                    break;
                case 2:
                    logEntries[numEntries].temperature = atof(token);
                    break;
                case 3:
                    logEntries[numEntries].humidity = atoi(token);
                    break;
                case 4:
                    logEntries[numEntries].light = atoi(token);
                    break;
                case 5:
                    strcpy(logEntries[numEntries].time, token);
                    break;
            }

            token = strtok(NULL, ",");
            tokenCount++;
        }

        numEntries++;
    }

    fclose(file);
}

void displayData() {
    if (numEntries == 0) {
        printf("No data to display.\n");
        return;
    }

    printf("EntryNo  SensorNo  Temperature  Humidity  Light  Time\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < numEntries; i++) {
        printf("%-8d %-9s %-12.1f %-9d %-6d %s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].time);
    }
}

int main() {
    readDataFromFile();
    displayData();

    return 0;
}
