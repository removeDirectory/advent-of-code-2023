#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *filePointer;
    filePointer = fopen("input.txt", "r");
    if (filePointer == NULL)
    {
        printf("not sure how this happened lmao");
        return 0;
    }
    char data[140][140];
    char c;
    int i = 0;
    int j = 0;
    while ((c = fgetc(filePointer)) != EOF)
    {
        if (c == '\n')
        {
            i++;
            j = 0;
            continue;
        }
        data[i][j] = c;
        j++;
    }

    int numberBuffer = 0;
    int countingNumber = 0;
    int runningTotal = 0;
    for (int i = 0; i < 140; i++)
    {
        for (int j = 0; j < 140; j++)
        {
            if (!('0' <= data[i][j] <= '9') && countingNumber == 1)
            {
                runningTotal += numberBuffer;
                numberBuffer = 0;
                countingNumber = 0;
                continue;
            }
            else if (!('0' <= data[i][j] <= '9'))
            {
                continue;
            }
            numberBuffer = (numberBuffer * 10) + (data[i][j] - '0');
            if (countingNumber == 1)
            {
                continue;
            }
            char testChars[] = "#@!\"£$%^&*()-_=+[]{};:,<.>/?\\|€";
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (!(0 <= (i + k) <= 140) || !(0 <= (j + l) <= 140))
                    {
                        continue;
                    }
                    if (strchr(testChars, data[i + k][j + l]))
                    {
                        countingNumber = 1;
                        break;
                    }
                }
                if (countingNumber == 1)
                {
                    break;
                }
            }
        }
    }

    printf("Total: %d", runningTotal);
}