#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums[] = {1, 2, 2, 3};
	int numsSize = 4;
	struct ListNode* head = ArrayToList(nums, numsSize);
	printList(head);
	head = deleteDuplicates(head);
	printList(head);

	return 0;
}
