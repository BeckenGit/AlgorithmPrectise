#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums[] = {1, 2, 3, 4};
	int numsSize = 4;
	struct ListNode* head = ArrayToList(nums, numsSize);
	printList(head);


	head = reverseList(head);

	printList(head);

	return 0;
}
