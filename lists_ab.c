
/*Maman 12 - System Programming
  Author - Ben Zeltser
  ID - 313327579

  In this program we will receive a String input from the user using
  'stdin' library. The input size is not pre-determined and isn't bounded.
  the user input will be stored in the memory.

  the program will feature the following:

  A.) The program will print in handsome presentation the given input.
      The size of every line will be fixed and symmetrical.

  B.) The program will sum up the amount of the total characters entered,
      and also the amount of them that are alphanumeric. And will return
      the two sums.*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define LINE 5
#define TRUE 1

/*Define a pointer to the input function that receives a 'char' type
  as an input from the user. */

char* input(char*);

/*Main execution of the function. the Memory allocation will be initated
  than for each iteration we will from a reallocation of memory within the
  input function. */

int main() {
char* inputString;
char* outputString;
int printLines(char* string);
/*Message the user for input*/
printf("Hello :-) Please enter a string: \n");
/*Continue to prompt the user until CTRL+Z is entered */
/*Init inputString */
inputString = '\0';
outputString = input(inputString);
printLines(outputString);

return 0;}

/*Section B */

char* input(char *string) {
    /*Variables explanation:
    'i' - running index
    'temp' - hold the current character for the i'th index
    'counter' - count indecies of Alphanumeric characters
    */
    int temp,i,counter;
    string = malloc(sizeof(char));
    counter = 0;
    temp = getchar();
    /*Set initially first char as NULL char*/
    string[0] = '\0';
    /*Iterate through the file*/
    for (i=0;temp!=EOF; i++) {
    /*Reallocate memory for 'string' for further incoming user input*/
        string = realloc(string, (i+2)*sizeof(char));
    /*Store the given input from the user inside the string*/
        string[i] = (char) temp;
    /*Set next char is NULL char*/
        string[i+1] = '\0';
    /*Check if the current char is alphanumeric*/
        if(isalnum(temp)) {
            counter = counter+1;}
    /*set temp as the current character */
        temp = getchar();
    }
    printf("\nTotal characters entered: %d \n", strlen(string));
    printf("Number of Alphanumeric characters entered: %d \n", counter);
    /*finished using the pointer. now we will free the memory. */

    return string;
    /*Free the memory when finished it's usage.*/
    free(string);
}

/*Section A */

int printLines(char* string) {
int i,length;
/*Variables explanation:
'i' - running index.
'length' - represents the size of 'string'. */

printf("\nBounded String:");
/*Here we will define a counter.
then we will go to a new line*/

length = strlen(string);

for (i=0; i<length; i++) {
/*if the counter is divisable by LINE (size) then start a new line */
    if (i%LINE == 0) {
        printf("\n");}
/*print the next character */
    printf("%c", string[i]);
}
printf("\n");
return 0;
}

