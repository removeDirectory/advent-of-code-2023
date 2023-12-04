#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *filePointer;
    char currentLine[300];
    memset(currentLine, '\0', sizeof(currentLine));
    filePointer = fopen("input.txt", "r");

    if (filePointer == NULL)
    {
        printf("Unable to open file");
        return 0;
    }

    char c;
    int i = 0;
    int lineNo = 0;
    int lineTotal = 0;
    while ((c = fgetc(filePointer)) != EOF)
    {
        if (c != '\n')
        {
            currentLine[i] = c;
            i++;
            continue;
        }

        lineNo++;
        int highestRed = 0;
        int highestBlue = 0;
        int highestGreen = 0;
        char *strPointer;
        strtok_r(currentLine, ":", &strPointer);
        char *value = strtok_r(NULL, ":", &strPointer);
        value = strtok_r(value, ";", &strPointer);

        do
        {
            char *colourValue;
            char *colour;
            colour = strtok_r(value, ",", &colourValue);
            do
            {
                int j = 1;
                int number = 0;
                while (colour[j] != ' ')
                {
                    if ('0' <= colour[j] <= '9')
                    {
                        number = (number * 10) + (colour[j] - '0');
                    }
                    j++;
                }
                int colourType = strlen(colour) - (j + 1);
                printf("%s has colour length of %d\n", colour, colourType);
                if (colourType == 3)
                {
                    if (number > highestRed)
                    {
                        highestRed = number;
                    }
                }
                else if (colourType == 4)
                {
                    if (number > highestBlue)
                    {
                        highestBlue = number;
                    }
                }
                else if (colourType == 5)
                {
                    if (number > highestGreen)
                    {
                        highestGreen = number;
                    }
                }
            } while (colour = strtok_r(NULL, ",", &colourValue));
        } while ((value = strtok_r(NULL, ";", &strPointer)) != NULL);

        int power = highestRed * highestBlue * highestGreen;
        lineTotal += power;

        // Reset for next line
        i = 0;
        memset(currentLine, '\0', sizeof(currentLine));
    }
    printf("Sum of line numbers is: %d\n", lineTotal);
    return 0;
}