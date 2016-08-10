#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums[3] = {1, 2, 3};
	int numsSize = 3;

	printf("%d\n", rob_bt(nums, numsSize));
	return 0;
}
