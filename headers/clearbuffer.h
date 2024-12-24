/* 
*   Function to clear out the buffer
*   Part of the program pw-killer
*   Author: Bruno Fernandes (github.com/realBruno)
*   Creation date: 23/12/2024
*/

#include <stdio.h>

char clearbuffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}