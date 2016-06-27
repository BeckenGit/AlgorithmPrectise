#include <stdio.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums[] = {1, 2, 3, 4};
	int numsSize = 4;
	printArray(nums, numsSize);
	moveZeroes(nums, numsSize);
	printArray(nums, numsSize);
  return 0;
}
