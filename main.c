/* 
*   PW-KILLER
*   Author: Bruno Fernandes (github.com/realBruno)
*   Creation date: 21/12/2024
*   Last updated: 21/12/2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "zip/winrar.h"
#include "zip/7zip.h"
#include "zip/unzip.h"

int main(void)
{   
    printf("PASSWORD CRACKER PROGRAM.\n");
    printf("Before using, see \"Guide\" on README.md\n\n");
    usleep(1000000);

    int filetype;
    printf("SELECT YOUR FILETYPE\n");
    printf("Zip (1) | PDF (2): ");
    scanf("%d", &filetype);
    
    switch(filetype)
    {
        case 1:
            int file_archive;
            printf("SELECT FILE ARCHIVE\n");
            printf("7-zip (1) | WinRAR (2) | Unzip (3): ");
            scanf("%d", &file_archive);
            break;
    }

    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    printf("Insert file path (100 char. max): ");
    char arr[101];
    scanf("%s", arr);

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    FILE *input = fopen(("%s", arr), "w");

    fprintf(input, "%d", 123);

    fclose(input);

    return 0;
}