#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string toUpper(string name);

int main(void)
{
    string name = GetString();
    if (name != NULL)
    {
        toUpper(name);
        int stringLen = strlen(name);
        printf("%c", name[0]);
        for (int i = 0; i < stringLen; i++) 
        {
            if (name[i] == ' ' && (i + 1 != strlen(name))) 
            {
                printf("%c", name[i + 1]);
            }
        }
        printf("\n");
    }
}

string toUpper(string name)
{
    // capitalizes all letters in name
    int n = strlen(name);
    for (int i = 0; i < n; i++) 
    {
        if (name[i] >= 'a' && name[i] <= 'z' ) 
        {
            name[i] = name[i] - ('a' - 'A');
        }
    }
    return name;
}