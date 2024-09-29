#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char data[140][140];
int totalRatio = 0;
int i = 0;
int j = 0;

void findRatio() {
    char num1[3] = { '0', '0', '0' };
    char num2[3] = { '0', '0', '0' };
    bool num1Used = false;
    bool readingNo = true;

    // loop over all adjacent numbers
    for (int k = -1; k < 2; k++) {
        if (!(0 <= (i + k) <= 140)) continue; // check bounds

        for (int l = -1; l < 2; l++) {
            if (!(0 <= (j + l) <= 140)) continue; // check bounds

            if (!('0' <= data[i + k][j + l] <= '9')) { // is number
                if (num1[0] != '0' || num1[1] != '0' || num1[2] != '0') num1Used = true;
                readingNo = true;
                continue;
            }

            // so don't read same no over and over
            if (!readingNo) continue;

            // read two chars either side of no found
            for (int delta = (j + l) - 2; delta < (j + l) + 3; delta++) {
                if (!(0 <= delta <= 140)) continue;
                if (!('0' <= data[i + k][delta] <= '9') || data[i + k][delta] == '.') continue; // TODO: fix this line

                printf("adding %c to num ", data[i + k][delta]);

                if (num1Used) {
                    num2[2] = num2[1];
                    num2[1] = num2[0];
                    num2[0] = data[i + k][delta];
                } else {
                    num1[2] = num1[1];
                    num1[1] = num1[0];
                    num1[0] = data[i + k][delta];
                }
            }
            readingNo = false; // to avoid reading same no twice
        }
    }

    // if there isn't two numbers, no ratio
    if (num2[0] == 0) return;

    // assemble numbers
    int ratio = ((num1[2] - '0') * 100) + ((num1[1] - '0') * 10) + (num1[0] - '0');
    printf("ratio: %i\n", ratio);
    ratio = ratio * ((num2[2] - '0') * 100) + ((num2[1] - '0') * 10) + (num2[0] - '0');

    totalRatio += ratio;
}

int main() {
    // read into buffer
    FILE *filePointer;
    filePointer = fopen("input.txt", "r");
    if (filePointer == NULL)
    {
        printf("not sure how this happened lmao");
        return 0;
    }
    
    char c;
    while ((c = fgetc(filePointer)) != EOF)
    {
        printf("%c", c);
        if (c == '\n')
        {
            i++;
            j = 0;
            continue;
        }
        data[i][j] = c;
        j++;
    }
    printf("\n");

    // find '*' and find calc ratio
    for (i = 0; i < 140; i++) {
        if (data[i][0] == '\0') break;

        for (j = 0; j < 140; j++) {
            if (data[i][j] == '*') findRatio();
            else if (data[i][j] == '\n') break;
        }
    }

    printf("total ratio: %i\n", totalRatio);
}

