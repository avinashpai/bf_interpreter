#include <stdio.h>

#define TAPE_SIZE 30000
#define SOURCE_SIZE 30000


char tape[TAPE_SIZE] = {0};
char *cell = tape;

char source[SOURCE_SIZE] = "++++++++++++++++++++++++++++++++++++++++++++++++.,."; 
char *ip = source;	// Instruction pointer


int main(void)
{
	while(*ip) {
		switch (*ip) {
			case '>':
				++cell;
				break;
			case '<': 
				--cell;
				break;
			case '+': 
				++*cell;
				break;
			case '-': 
				--*cell;
				break;
			case '.': 
				putchar(*cell);
				break;
			case ',': 
				*cell = getchar();
				break;
			case '[': break;
			case ']': break;
		}

		// putchar(*ip);
		ip++;
	}


	return 0;
}
