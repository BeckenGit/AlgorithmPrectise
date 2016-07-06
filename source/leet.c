#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int num = 19;
	if(isHappy(num))
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
