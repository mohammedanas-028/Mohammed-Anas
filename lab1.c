#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a day in the calendar
struct Day {
    char* dayName;
    int date;
    char* activity;
};

// Function to create a day and return its pointer
struct Day* createDay() {
    struct Day* newDay = (struct Day*)malloc(sizeof(struct Day));
    
    // Allocate memory for dynamic strings
    newDay->dayName = (char*)malloc(sizeof(char) * 20);
    newDay->activity = (char*)malloc(sizeof(char) * 100);
    
    return newDay;
}

// Function to read data for a day from the keyboard
void readDay(struct Day* day) {
    printf("Enter day name: ");
    scanf("%s", day->dayName);

    printf("Enter date: ");
    scanf("%d", &day->date);

    printf("Enter activity: ");
    scanf(" %[^\n]s", day->activity);
}

// Function to display the calendar
void displayCalendar(struct Day* calendar[], int size) {
    printf("\nCalendar:\n");
    for (int i = 0; i < size; ++i) {
        printf("Day: %s, Date: %d, Activity: %s\n", calendar[i]->dayName, calendar[i]->date, calendar[i]->activity);
    }
}

int main() {
    int weekSize = 7;
    struct Day* calendar[weekSize];

    // Creating the calendar
    for (int i = 0; i < weekSize; ++i) {
        calendar[i] = createDay();
        readDay(calendar[i]);
    }

    // Displaying the calendar
    displayCalendar(calendar, weekSize);

    // Freeing allocated memory
    for (int i = 0; i < weekSize; ++i) {
        free(calendar[i]->dayName);
        free(calendar[i]->activity);
        free(calendar[i]);
    }

    return 0;
}
