#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums[5] = {1, 2, 3, 4, 5};
	int numsSize = 5;
	struct ListNode* head = ArrayToList(nums, numsSize);
	struct ListNode* node5 = listNodeOfVal(head, 5);
	struct ListNode* node3 = listNodeOfVal(head, 3);
	printList(head);
	//node5 -> next = node3;
	if(hasCycle(head))
		printf("Yes!\n");
	else
		printf("No!\n");
	return 0;
}
