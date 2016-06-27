#include <stdio.h>
#include <malloc.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums1[4] = {1, 2, 2, 1};
	int nums1Size = 4;

	int nums2[2] = {2, 2};
	int nums2Size = 2;

	printArray(nums1, nums1Size);
	printArray(nums2, nums2Size);

	int* returnSize = (int*)malloc(sizeof(int));
	int* returnNums = intersection(nums1, nums1Size, nums2, nums2Size, returnSize);

	printArray(returnNums, *returnSize);

	return 0;
}
