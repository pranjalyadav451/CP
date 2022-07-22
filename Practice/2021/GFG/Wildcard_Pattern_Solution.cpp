#include <stdio.h>
#include <string.h>

// Define the maximum length of pattern or input string
#define LEN 210

// Create a DP lookup table
int lookup[LEN][LEN];

// Function that matches an input string with a given wildcard pattern
int isMatching(char str[], char pattern[], int n, int m) {
    // If both the input string and pattern reach their end,
    // return true
    if (m < 0 && n < 0) {
        return 1;
    }

    // If only the pattern reaches its end, return false
    else if (m < 0) {
        return 0;
    }

    // If only the input string reaches its end, return true
    // if the remaining characters in the pattern are all `*`
    else if (n < 0) {
        for (int i = 0; i <= m; i++) {
            if (pattern[i] != '*') {
                return 0;
            }
        }

        return 1;
    }

    // If the subproblem is encountered for the first time
    if (lookup[m][n] == -1) {
        if (pattern[m] == '*') {
            // 1. `*` matches with current characters in the input string.
            // Here, we will move to the next character in the string.

            // 2. Ignore `*` and move to the next character in the pattern
            lookup[m][n] = isMatching(str, pattern, n - 1, m) ||
                isMatching(str, pattern, n, m - 1);
        }
        else {
            // If the current character is not a wildcard character, it
            // should match the current character in the input string
            if (pattern[m] != '?' && pattern[m] != str[n]) {
                lookup[m][n] = 0;
            }
            // check if `pattern[0…m-1]` matches `str[0…n-1]`
            else {
                lookup[m][n] = isMatching(str, pattern, n - 1, m - 1);
            }
        }
    }

    return lookup[m][n];
}

// Wildcard Pattern Matching Implementation in C
int main(void) {
    char str[] = "xyxzzxy";
    char pattern[] = "x***x?";

    memset(lookup, -1, sizeof(lookup));

    if (isMatching(str, pattern, strlen(str) - 1, strlen(pattern) - 1)) {
        printf("Match");
    }
    else {
        printf("No Match");
    }

    return 0;
}

