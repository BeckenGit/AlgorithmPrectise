#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int steps = 44;
	printf("%d steps has %d ways to reach !\n", steps, climbStairs(steps));

	return 0;
}
