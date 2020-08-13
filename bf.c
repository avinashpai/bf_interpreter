#include <stdio.h>
#include <errno.h>

#define VERSION "v1.0.0"

#define TAPE_SIZE 30000
#define SOURCE_SIZE 30000


char tape[TAPE_SIZE] = {0};
char *cell = tape;

char source[SOURCE_SIZE];
char *ip = source;	// Instruction pointer

int loop;


void execute()
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
			case '[': 
				if (!*cell) {	// If cell at data pointer is zero
					loop = 1;

					while (loop) {	// loop var holes a number of '[]'
						ip++;	// increment instruction pointer

						if (*ip == '[') loop++;
						if (*ip == ']') loop--;
					}
				}
				break;
			case ']': 
				loop = 1;
				while (loop) {
					ip--;

					if (*ip == '[') loop--;
					if (*ip == ']') loop++;
				}

				ip--;

				break;
		}

		ip++;
	}

}

int main(int argc, char *argv[])
{
	if (argc == 1) {
		printf("\n Brainfuck interpreter %s by Avinash Pai\n", VERSION);
		printf("\t1. Type or paste in brainfuck source code\n");
		printf("\t2. Use Ctrl-D for code execution (Unix)\n");
		printf("\t3. Use ./bf [filename] to execute source file\n");
		printf("\n\t\tHappy brainfucking!\n\n");

		fread(source, 1, SOURCE_SIZE - 1, stdin);
		execute();
	}
	else if (argc == 2) {
		FILE *file = fopen(argv[1], "r");

		if (errno) {
			printf("File '%s' doesn't  exist!\n", argv[1]);
			return 1;
		}

		fread(source, 1, SOURCE_SIZE, file);
		fclose(file);
		execute();
	}

	return 0;
}
