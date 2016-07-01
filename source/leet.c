#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	char* s = "abc";
	char* t = "def";
	bool r = isAnagram(s, t);

	if(r)
		printf("It's anagram!\n");
	else
		printf("It's not anagram!\n");

	return 0;
}
