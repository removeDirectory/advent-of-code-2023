#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    // Variables
    FILE *filePointer;
    char currentWord[100];
    filePointer = fopen("part 1 input.txt", "r");

    // Checks if file exists
    if (filePointer == NULL)
    {
        printf("Unable to open file");
        return 0;
    }

    // File read loop
    int arrayIndex = 0;
    int runningTotal = 0;
    char c;

    while ((c = fgetc(filePointer)) != EOF)
    {
        // Checks for end of word
        if (c != '\n')
        {
            currentWord[arrayIndex] = c;
            arrayIndex++;
            continue;
        }

        // Checks over the word for numbers
        int firstNumber = -1;
        int lastNumber = -1;
        for (int i = 0; i <= arrayIndex; i++)
        {
            if (47 < currentWord[i] && currentWord[i] < 59)
            {
                if (firstNumber == -1)
                {
                    firstNumber = currentWord[i] - 48;
                    continue;
                }
                lastNumber = currentWord[i] - 48;
                continue;
            } // Safe until here

            char letterNo[5];
            int j = 0;
            char numbers[9][6] = {
                "one",
                "two",
                "three",
                "four",
                "five",
                "six",
                "seven",
                "eight",
                "nine"};
            char loadBuffer[6];
            memset(loadBuffer, '\0', sizeof(loadBuffer));
            strncpy(loadBuffer, &currentWord[i], 5);
            if (loadBuffer[2] == '\0')
            {
                continue;
            }

            int tempMatch = -1;
            for (int k = 0; k < 9; k++)
            {
                if (strncmp(loadBuffer, numbers[k], strlen(numbers[k])) == 0)
                {
                    tempMatch = k + 1;
                    break;
                }
            }

            if (tempMatch == -1)
            {
                continue;
            }

            if (firstNumber == -1)
            {
                firstNumber = tempMatch;
                continue;
            }
            lastNumber = tempMatch;
        }

        // After here is safe
        int output[2];
        if (firstNumber == -1)
        {
            printf("not sure how this happened lmao");
            return 0;
        }
        else if (lastNumber == -1)
        {
            output[0] = firstNumber;
            output[1] = firstNumber;
        }
        else
        {
            output[0] = firstNumber;
            output[1] = lastNumber;
        }

        int total = (output[0] * 10) + output[1];
        runningTotal += total;

        printf("%d\n", total);
        printf("Total: %d\n", runningTotal);

        memset(currentWord, '\0', sizeof(currentWord));
        arrayIndex = 0;
    }
    printf("Final Total: %d\n", runningTotal);
    return 0;
}
