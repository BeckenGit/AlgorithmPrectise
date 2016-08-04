#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums[5] = {1, 2, 3, 4, 5};
	int numsSize = 5;
	struct ListNode* head = ArrayToList(nums, numsSize);
	head = swapPairs(head);
	printList(head);
	return 0;
}
