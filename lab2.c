#include <stdio.h>

// Function to find the length of a string
int stringLength(char str[]) {
    int len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

// Function to check if pattern PAT exists in main string STR
int patternExists(char str[], char pat[]) {
    int i, j;
    int strLen = stringLength(str);
    int patLen = stringLength(pat);

    for (i = 0; i <= strLen - patLen; i++) {
        for (j = 0; j < patLen; j++) {
            if (str[i + j] != pat[j]) {
                break;
            }
        }
        if (j == patLen) {
            return i; // Pattern found, return the index
        }
    }

    return -1; // Pattern not found
}

// Function to replace pattern PAT with replace string REP in main string STR
void replacePattern(char str[], char pat[], char rep[]) {
    int index = patternExists(str, pat);

    while (index != -1) {
        // Shift characters to the right to make space for replacement
        int strLen = stringLength(str);
        int patLen = stringLength(pat);
        int repLen = stringLength(rep);

        for (int i = strLen; i >= index + patLen; i--) {
            str[i + repLen - patLen] = str[i];
        }

        // Copy replace string REP into main string STR
        for (int i = 0; i < repLen; i++) {
            str[index + i] = rep[i];
        }

        // Find the next occurrence of the pattern
        index = patternExists(str, pat);
    }
}

int main() {
    char mainString[100], pattern[50], replace[50];

    // Read main string, pattern, and replace string
    printf("Enter the main string: ");
    scanf("%s", mainString);

    printf("Enter the pattern string: ");
    scanf("%s", pattern);

    printf("Enter the replace string: ");
    scanf("%s", replace);

    // Perform pattern matching and replacement
    int index = patternExists(mainString, pattern);

    if (index != -1) {
        replacePattern(mainString, pattern, replace);
        printf("Pattern found and replaced: %s\n", mainString);
    } else {
        printf("Pattern not found in the main string.\n");
    }

    return 0;
}
