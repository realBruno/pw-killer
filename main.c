/*
 *   PW-KILLER
 *   Author: Bruno Fernandes (github.com/realBruno)
 *   Creation date: 21/12/2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "./headers/clearbuffer.h"

#define MAX_PATH_SIZE 51
#define SYSTEM_ARGUMENT 201

int main(void)
{
    printf("PASSWORD CRACKER PROGRAM.\n");
    printf("Before using, see \"Guide\" on README.md\n\n");
    usleep(1000000);

    printf("Insert file path (%d char. max): ", MAX_PATH_SIZE - 1);
    char file_path[MAX_PATH_SIZE];
    scanf("%s", file_path);

    clearbuffer();

    printf("Insert where to extract file (%d char. max): ", MAX_PATH_SIZE - 1);
    char extraction_path[MAX_PATH_SIZE];
    scanf("%s", extraction_path);

    clearbuffer();

    // BUILDING COMMAND TO EXTRACT FILE
    char command[SYSTEM_ARGUMENT] = "7z x ";
    int command_size = sizeof(command) - strlen(command) - 1;
    strncat(command, file_path, command_size);
    strncat(command, " -o", command_size);
    strncat(command, extraction_path, command_size);
    strncat(command, " -aoa", command_size);
    strncat(command, " -p", command_size);

    int len_command = strlen(command);
    long long variable = 0;
    for (int k = 1; variable <= 10000000000, k != 0; )
    {
        sprintf(&command[len_command], "%lld", variable++);
        k = system(command);
    }
    
    variable--;
    char save_password;
    printf("Password found: \'%lld\'", variable);
    printf("\nSave password to file? (y/n) ");
    scanf("%c", &save_password);
    save_password == tolower(save_password);

    clearbuffer();  

    if (save_password == 'y')
    {
        FILE *output = fopen("password.txt", "w");
        fprintf(output, "%lld", variable);
        fclose(output);
        printf("Password saved successfully. Check \'password.txt\'.\n");
    }

    sleep(1);
    printf("Exiting...\n");
    sleep(1);

    return 0;
}