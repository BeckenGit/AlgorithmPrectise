#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int num;
	scanf("%d", &num);
	if(isPowerOfFour(num))
		printf("yes!\n");
	else
		printf("no!\n");
	return 0;
}
