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
    while((c = fgetc(filePointer)) != EOF) {
	// Checks if it's the end of the word
        if (c != '\n') {
            currentWord[arrayIndex] = c;
	    arrayIndex++;
            continue;
        }
        
	// Runs the number loop once word has been read in
        char firstNumber = '\0';
        char lastNumber = '\0';
        for (int i = 0; i <= arrayIndex; i++) {
	    if (47 < currentWord[i] && currentWord[i] < 59) {
                if (firstNumber == '\0') {
                    firstNumber = currentWord[i];
                    continue;
                }
                lastNumber = currentWord[i];
            }
        }

	// Creates output
	char output[2];
        if (firstNumber == '\0') {
            printf("Somehow this broke");
            return 0;
        }
	if (lastNumber == '\0') {
 	    output[0] = firstNumber;
	    output[1] = firstNumber;
	}
	else {
	    output[0] = firstNumber;
	    output[1] = lastNumber;
	}
	printf("%c", output[0]);
	printf("%c\n", output[1]);

	int total = ((output[0] - 48) * 10) + (output[1] - 48);
	runningTotal = runningTotal + total;
	printf("Current Total: %d\n", runningTotal);
	arrayIndex = 0;

	for(int i = 0; i < 100; i++) {
	    currentWord[i] = '\0';
	}
    }
    printf("%d\n", runningTotal);
    return 0;
}
