#include <stdio.h>
#include <stdlib.h>

int main() {
    // Variables
    FILE *filePointer;
    char currentWord[100];
    filePointer = fopen("part 1 input.txt", "r");

    // Checks if file exists
    if (filePointer == NULL) {
        printf("Unable to open file");
        return 0;
    }

    // File read loop
    int arrayIndex = 0;
    int runningTotal = 0;
    char c;
    
    while ((c = fgetc(filePointer)) != EOF) {
        // Checks for end of word
        if (c != '\n') {
            currentWord[arrayIndex] = c;
            arrayIndex++;
            continue;
        }
        
        // Checks over the word for numbers
        int firstNumber = -1;
        int lastNumber = -1;
        for (int i = 0; i <= arrayIndex; i++) {
            if (47 < currentWord[i] && currentWord[i] < 59) {
                if (firstNumber == -1) {
                    firstNumber = currentWord[i] - 48;
                    continue;
                }
                lastNumber = currentWord[i] - 48;
                continue;
            }
            
            char letterNo[5];
            int j = 0;
            char numbers[11][5] = {
                { 'z', 'e', 'r', 'o', '\0' },
                { 'o', 'n', 'e', '\0', '\0' },
                { 't', 'w', 'o', '\0', '\0' },
                { 't', 'h', 'r', 'e', 'e' },
                { 'f', 'o', 'u', 'r', '\0' },
                { 'f', 'i', 'v', 'e', '\0' },
                { 's', 'i', 'x', '\0', '\0' },
                { 's', 'e', 'v', 'e', 'n' },
                { 'e', 'i', 'g', 'h', 't' },
                { 'n', 'i', 'n', 'e', '\0' },
                { 't', 'e', 'n', '\0', '\0' }
            };
            int tempNumberIndex = -1;
            int numberIndex = -1;
            while (j < 5 && (i+j) <= arrayIndex) {
                letterNo[j] = currentWord[i+j];
                int foundNo = 0;
                for (int k = 0; k < 10; k++) {
                    if (letterNo[j] == numbers[k][j]) {
                        if (tempNumberIndex == -1) {
                            tempNumberIndex = k;
                            foundNo = 1;
                            break;
                        }
                        if ((tempNumberIndex == 4 || tempNumberIndex == 5) && (k != 4 && k != 5)) {
                            tempNumberIndex = k;
                            foundNo = 1;
                            break;
                        }
                        else if ((tempNumberIndex == 2 || tempNumberIndex == 3) && (k != 2 && k != 3)) {
                            tempNumberIndex = k;
                            foundNo = 1;
                            break;
                        }
                        else if ((tempNumberIndex == 6 || tempNumberIndex == 7) && (k != 6 && k != 7)) {
                            tempNumberIndex = k;
                            foundNo = 1;
                            break;
                        }
                    }
                }
                if (foundNo == 0) {
                    break;
                }
                if (j == 2) {
                    if (numberIndex == 1 || numberIndex == 2 || numberIndex == 6) {
                        numberIndex = tempNumberIndex;
                        break;
                    }
                }
                else if (j == 3) {
                    if (numberIndex == 0 || numberIndex == 4 || numberIndex == 5 || numberIndex == 9) {
                        numberIndex = tempNumberIndex;
                        break;
                    }
                }
                else if (j == 4) {
                    if (numberIndex == 3 || numberIndex == 7 || numberIndex == 8) {
                        numberIndex = tempNumberIndex;
                        break;
                    }
                }
                j++;
            }
            if (numberIndex != -1) {
                if (firstNumber == -1) {
                    firstNumber = numberIndex;
                    continue;
                }
                else {
                    lastNumber = numberIndex;
                    continue;
                }
            }
        }
        
        int output[2];
        if (firstNumber == -1) {
            printf("not sure how this happened lmao");
            return 0;
        }
        else if (lastNumber == -1) {
            output[0] = firstNumber;
            output[1] = firstNumber;
        }
        else {
            output[0] = firstNumber;
            output[1] = lastNumber;
        }

        int total = (output[0] * 10) + output[1];
        runningTotal += total;

        printf("%d\n", total);
        printf("Total: %d\n", runningTotal);

        for (int i = 0; i < 100; i++) {
            currentWord[i] = '\0';
        }
    }
    printf("Total: %d\n", runningTotal);
    return 0;
}
