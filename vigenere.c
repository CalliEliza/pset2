#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define upper 65
#define lower 97

int checkArgs(int);
string cipher(string, string);
char encrypt(int, string, int);

int main (int argc, string argv[]) {
  
  int consoleArgs = checkArgs(argc);
  if(consoleArgs == 1){
    return 1;
  }
  
  string key = argv[1];
  
  for (int i = 0, keylen = strlen(argv[1]); i < keylen; i++)
    {
        if ((key[i] >= '0') && (key[i] <= '9'))
        {
            printf("Try again.\n");
            return 1;
        }
    }
  
  string userInput = GetString();
 
  cipher(userInput, key);

  return 0;
}

int checkArgs (int count) {

  if(count == 2) {
    return 0;

  } 
  else if(count < 2) {
    printf("Please try again.\n");
    return 1;

  } 
  else {
    printf("Please try again.\n");
    return 1;
  }
}

string cipher(string userInput, string key) {
  int inputLen = strlen(userInput);

  int newChar;
  int counter = 0;
  for(int i = 0; i < inputLen; i++) {
    newChar = userInput[i];

    if(isalpha(newChar)) {
      encrypt(newChar, key, counter);

    
      counter++;

    } else {
      printf("%c", newChar);
    } 
  }

  printf("\n");
  return 0;
}

char encrypt(int newChar, string key, int counter) {

  int index;

  // if uppercase char
  if(isupper(newChar)) {
    index = upper;

  // if lowercase char
  } 
  else {
    index = lower;
  }

  char encryptedChar;
  int keywordLen = strlen(key);

  int ciphNum = key[counter % keywordLen] - lower;

  ciphNum = (((newChar - index) + ciphNum) % 26);

  encryptedChar = index + ciphNum;

  printf("%c", encryptedChar);

  return 0;
}
