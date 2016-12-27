#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

string message;
int key = 0;

int main(int argc, string argv[]) 
{
    //checks number of args, if correct moves on if not exits with code 1
    if (argc != 2) {
        printf("Try again\n");
        return 1;
    }
        key = atoi(argv[1]);
    
    // gets user input for message to be encoded
    do {
        message = GetString();
    }
    while(message == NULL);
    
     // creates length variable of given message
    int length = strlen(message);
    for (int i = 0; i < length; i++) 
    {
        if (message[i] == 32 || message[i] == 33 || message[i] == 44) 
        {
            printf("%c", message[i]);
        }
        if (isalpha(message[i]))
        {
            if (isupper(message[i]))
            {
                message[i] = ((((message[i] - 64) +key) % 26) + 64);
                printf("%c", message[i]);
            }
            else if (islower(message[i]))
            {
                message[i] = ((((message[i] - 96) +key) % 26) + 96);
                printf("%c", message[i]);
            }
            else 
            {
                printf("%c", message[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
