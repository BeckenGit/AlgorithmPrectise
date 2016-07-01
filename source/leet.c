#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	char* s = "abc";
	char* t = "def";
	int i = 0;
	while(s[i] != '\0'){
		printf("%c ", s[i]);
		if(s[i] == 'b'){
			printf("\nbreak!\n");
			break;
		}

		i++;
	}

	return 0;
}
