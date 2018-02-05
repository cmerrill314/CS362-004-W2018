#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

char* stringBuffer = 0;

char inputChar()
{
    //Characters for test case are limited to the characters in testme()
	char charset[] = {'[', '(', '{', ' ', 'a', 'x', '}', ')', ']'};
	
	//Generate a random index from 0-8
	int n = rand() % 9;
	
	//Return the character with the random index
    return charset[n];
}

char *inputString()
{
	int i;
	char *str = malloc(sizeof(char) * 6);
	
	//Characters for this case are limited to the characters in the word 'reset'
	const char charset[] = "rest";
	
	//Clear any existing strings in the buffer
	if(stringBuffer != 0)
		free(stringBuffer);
	
	//Add 5 random letters to the string
	for (i = 0; i < 5; i++) {
		int n = rand() % 4;
		str[i] = charset[n];
	}
	
	//End the string with a null terminator
	str[5] = '\0';
	
	//Assign the created string to the buffer
	stringBuffer = str;
	
	//Return random string
    return stringBuffer;
}

void testme()
{
  int tcCount = 0;
  char *s;
  char c;
  int state = 0;
  
  while (1)
  {
    tcCount++;
    c = inputChar();
    s = inputString();
    printf("Iteration %d: c = %c, s = %s, state = %d\n", tcCount, c, s, state);

    if (c == '[' && state == 0) state = 1;
    if (c == '(' && state == 1) state = 2;
    if (c == '{' && state == 2) state = 3;
    if (c == ' '&& state == 3) state = 4;
    if (c == 'a' && state == 4) state = 5;
    if (c == 'x' && state == 5) state = 6;
    if (c == '}' && state == 6) state = 7;
    if (c == ')' && state == 7) state = 8;
    if (c == ']' && state == 8) state = 9;
    if (s[0] == 'r' && s[1] == 'e'
       && s[2] == 's' && s[3] == 'e'
       && s[4] == 't' && s[5] == '\0'
       && state == 9)
    {
      printf("error ");
      exit(200);
    }
  }
}


int main(int argc, char *argv[])
{
    srand(time(NULL));
    testme();
    return 0;
}
