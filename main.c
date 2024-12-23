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

#define MAX_PATH_SIZE 51
#define SYSTEM_ARGUMENT 201

void generate_password(int x);

int main(void)
{   
    printf("PASSWORD CRACKER PROGRAM.\n");
    printf("Before using, see \"Guide\" on README.md\n\n");
    usleep(1000000);

    printf("Insert file path (%d char. max): ", MAX_PATH_SIZE - 1);
    char file_path[MAX_PATH_SIZE];
    scanf("%s", file_path);
    
    char c;
    while ((c = getchar()) != '\n' && c != EOF) // clears buffer
        ;
    
    printf("Insert where to extract file (%d char. max): ", MAX_PATH_SIZE - 1);
    char extraction_path[MAX_PATH_SIZE];
    scanf("%s", extraction_path);

    // BUILDING COMMAND TO EXTRACT FILE
    char command[SYSTEM_ARGUMENT] = "7z x ";
    int command_size = sizeof(command) - strlen(command) - 1;
    strncat(command, file_path, command_size);
    strncat(command, " -o", command_size);
    strncat(command, extraction_path, command_size);
    strncat(command, " -p", command_size);

    // ABOUT THE PASSWORD
    printf("\nInclude characters to the password.\nKeep in mind that "
            "the more types you include, the less likely it is for"
            " the program to find the correct password.\n");

    char include_numbers;
    printf("Include numbers? (y/n): ");
    scanf("%c", &include_numbers);
    
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    char include_upper;
    printf("Include uppercase letters? (y/n): ");
    scanf("%c", &include_upper);

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    char include_lower;
    printf("Include lowercase letters? (y/n): ");
    scanf("%c", &include_lower);

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    char include_special;
    printf("Include special characters? (y/n): ");
    scanf("%c", &include_special);

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    int up_to;
    printf("Insert maximum length the password may reach (0-50): ");
    scanf("%d", &up_to);

    while ((c = getchar()) != '\n' && c != EOF)
        ;

    strncat(command, "123", command_size);
    while (system(command) != 0)
    {
        ;
    }

    return 0;
}

// FUNCTION DEFINITION
void generate_password(int x) // x is the max length the password can reach
{                            // aka "up_to"
    int password_len = rand() % x;
    char password[password_len];

    
}