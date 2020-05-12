#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <regex.h>


// Toggles printf statements throughout the program to determine where bugs are in the code
// Set to "true" to enable the statements and "false" to disable them
#define DEBUG_STATEMENTS_ON false
// Using messenger's max character limit of 2000 + 1 for the null sentinel
#define MAX_CHAR_LIMIT 2001


// Takes a 5-bit word in an array and returns its integer value
int reconstruct(int *binaryRep, int position);

void main(int argc, char **argv)
{
  int iteration, index = 0, comparison;
  int charToNum, tempHold1, tempHold2, strSize;
  char inputStr[MAX_CHAR_LIMIT];
  bool allValid = true;
  regex_t regex;


  // **Reading the Input**
  // Take in user-specified text, and record the length once
  printf("Input {2000 Characters Max}: ");
  fgets(inputStr, MAX_CHAR_LIMIT, stdin);
  strSize = strlen(inputStr);

  // If the string is less than the buffer size, the null sentinel gets counted as a character in
  // the plaintext; this statement will remove said null sentinel for encryption
  if (strSize < MAX_CHAR_LIMIT - 1)
  {
    strSize -= 1;
  }

  // Terminate the program if there is no input text at all
  if (strSize == 0)
  {
    printf("Error: Must specify input\n");
    exit(EXIT_FAILURE);
  }

  // Run through the entirety of the input text
  for (iteration = 0; iteration < strSize; iteration++)
  {
    // Consistently check to see if the string alphabetic allowing spaces; if not, raise a "flag"
    comparison = regcomp(&regex, "[/sa-zA-z]", 0);
    if (comparison != 0)
      allValid = false;
  }

  if (DEBUG_STATEMENTS_ON)
    printf("*INPUT TEXT READ [Length: %d]*\n", strSize);

  // Terminate the program in the case that the input text contains numbers/symbols
  if (!allValid)
  {
    printf("Error: Input text must be strictly syntactic [A-Z, a-z, {spaces}]\n");
    exit(EXIT_FAILURE);
  }

  // Static arrays to manipulate the binary representations of the text
  int plaintext[strSize * 5];
  int ciphertext[strSize * 5];
  int outputInt[strSize];
  char outputChar[strSize];

  if (DEBUG_STATEMENTS_ON)
    printf("*STATIC ARRAYS CREATED*\n");


  // **Conversion to Bits**
  for (iteration = 0; iteration < strSize; iteration++)
  {
    charToNum = inputStr[iteration];

    switch(charToNum)
    {
      case ' ':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'A':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'B':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'C':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
      case 'D':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'E':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'F':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'G':
        plaintext[index] = 0;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
      case 'H':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'I':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'J':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'K':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
      case 'L':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'M':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'N':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'O':
        plaintext[index] = 0;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
      case 'P':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'Q':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'R':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'S':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
      case 'T':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'U':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'V':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'W':
        plaintext[index] = 1;
        plaintext[index + 1] = 0;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
      case 'X':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'Y':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'Z':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'a':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 0;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
      case 'b':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 0;
        break;
      case 'c':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 0;
        plaintext[index + 4] = 1;
        break;
      case 'd':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 0;
        break;
      case 'e':
        plaintext[index] = 1;
        plaintext[index + 1] = 1;
        plaintext[index + 2] = 1;
        plaintext[index + 3] = 1;
        plaintext[index + 4] = 1;
        break;
    }

    // Iterate the index by 5 for the next word
    index = index + 5;
  }

  if (DEBUG_STATEMENTS_ON)
  {
    printf("*CONVERTED TO BITS [Bits: ");
    for (iteration = 0; iteration < strSize * 5; iteration++)
    {
      printf("%d", plaintext[iteration]);
      if ((iteration + 1) % 5 == 0 && iteration != (strSize * 5) - 1)
        printf(" ");
    }
    printf("]*\n");
  }


  // **Shift Right**
  // Index will be one above the length of our binary representation arrays
  tempHold1 = plaintext[index - 1];
  tempHold2 = plaintext[index - 2];
  for (iteration = index - 1; iteration > 1; iteration--)
  {
    // Move every element to the index 2 on the right, then move the last 2 elements to the beginning
    plaintext[iteration] = plaintext[iteration - 2];
  }
  plaintext[1] = tempHold1;
  plaintext[0] = tempHold2;

  if (DEBUG_STATEMENTS_ON)
  {
    printf("*SHIFTED RIGHT [Bits: ");
    for (iteration = 0; iteration < strSize * 5; iteration++)
    {
      printf("%d", plaintext[iteration]);
      if ((iteration + 1) % 5 == 0 && iteration != (strSize * 5) - 1)
        printf(" ");
    }
    printf("]*\n");
  }


  // **Reversing the Bit Order**
  for(iteration = 0; iteration < index; iteration++)
  {
    ciphertext[(index - 1) - iteration] = plaintext[iteration];
  }

  if (DEBUG_STATEMENTS_ON)
  {
    printf("*BITS REVERSED [Bits: ");
    for (iteration = 0; iteration < strSize * 5; iteration++)
    {
      printf("%d", ciphertext[iteration]);
      if ((iteration + 1) % 5 == 0 && iteration != (strSize * 5) - 1)
        printf(" ");
    }
    printf("]*\n");
  }


  // **Conversion to Text**
  // First, take the words in the ciphertext and iterate by the word size to convert the binary
  // back into integers
  for(iteration = 0; iteration < index; iteration += 5)
  {
    if (DEBUG_STATEMENTS_ON)
      printf("\t*LOOP %d BEGUN*\n", ((iteration + 1) / 5) + 1);
    outputInt[(iteration + 1) / 5] = reconstruct(ciphertext, iteration);
    if (DEBUG_STATEMENTS_ON)
      printf("\t*LOOP %d COMPLETED*\n", ((iteration + 1) / 5) + 1);
  }

  if (DEBUG_STATEMENTS_ON)
  {
    printf("*CONVERTED TO INTS [Ints: ");
    for (iteration = 0; iteration < strSize; iteration++)
    {
      printf("%d", outputInt[iteration]);
      if (iteration != strSize - 1)
        printf(" ");
    }
    printf("]*\n");
  }

  // Then, run through a predetermined map of characters to get the character and print the
  // completed ciphertext
  printf("Output: ");
  for(iteration = 0; iteration < strSize; iteration++)
  {
    switch(outputInt[iteration])
    {
      case 1:
        outputChar[iteration] = 'a';
        break;
      case 2:
        outputChar[iteration] = 'b';
        break;
      case 3:
        outputChar[iteration] = 'c';
        break;
      case 4:
        outputChar[iteration] = 'd';
        break;
      case 5:
        outputChar[iteration] = 'e';
        break;
      case 6:
        outputChar[iteration] = 'f';
        break;
      case 7:
        outputChar[iteration] = 'g';
        break;
      case 8:
        outputChar[iteration] = 'h';
        break;
      case 9:
        outputChar[iteration] = 'i';
        break;
      case 10:
        outputChar[iteration] = 'j';
        break;
      case 11:
        outputChar[iteration] = 'k';
        break;
      case 12:
        outputChar[iteration] = 'l';
        break;
      case 13:
        outputChar[iteration] = 'm';
        break;
      case 14:
        outputChar[iteration] = 'n';
        break;
      case 15:
        outputChar[iteration] = 'o';
        break;
      case 16:
        outputChar[iteration] = 'p';
        break;
      case 17:
        outputChar[iteration] = 'q';
        break;
      case 18:
        outputChar[iteration] = 'r';
        break;
      case 19:
        outputChar[iteration] = 's';
        break;
      case 20:
        outputChar[iteration] = 't';
        break;
      case 21:
        outputChar[iteration] = 'u';
        break;
      case 22:
        outputChar[iteration] = 'v';
        break;
      case 23:
        outputChar[iteration] = 'w';
        break;
      case 24:
        outputChar[iteration] = 'x';
        break;
      case 25:
        outputChar[iteration] = 'y';
        break;
      case 26:
        outputChar[iteration] = 'z';
        break;
      case 27:
        outputChar[iteration] = ' ';
        break;
    }
    printf("%c", outputChar[iteration]);
  }
  printf("\n");

  if (DEBUG_STATEMENTS_ON)
    printf("*CIPHERTEXT PRINTED*\n");
}

int reconstruct(int *binaryRep, int position)
{
  int iteration, iteration2;
  int sum = 0, addition = 1;

  if (DEBUG_STATEMENTS_ON)
  {
    printf("\t\t*FUNCTION CALL BEGUN*\n");
    printf("\t\t\t*[Start Index: %d, Bits: ", position);
  }

  // Reads a single word
  for (iteration = 5; iteration > 0; iteration--)
  {
    if (DEBUG_STATEMENTS_ON)
      printf("%d", binaryRep[position + (5 - iteration)]);

    // Based on the binary value of an index, its corresponding value in decimal is added
    if (binaryRep[position + (5 - iteration)] == 1)
    {
      // Since using the pow() function from math.h requires the use of the -lm flag during
      // compilation, I opted t manually compute the powers of 2
      for (iteration2 = 0; iteration2 < iteration - 1; iteration2++)
        addition *= 2;
      sum += addition;
    }
    // Reset the addition value
    addition = 1;
  }

  if (DEBUG_STATEMENTS_ON)
  {
    printf(", Int: %d]*\n", sum);
    printf("\t\t*FUNCTION CALL COMPLETED*\n");
  }

  return sum;
}
