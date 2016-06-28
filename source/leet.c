#include <stdio.h>
#include <malloc.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums[4] = {1, 2, 3, 4};
	int numsSize = 4;

	struct ListNode* head = ArrayToList(nums, numsSize);
	printList(head);

	struct ListNode* node = head -> next;
	printf("Delete second node: %d\n", node -> val);
	deleteNode(node);

	printList(head);

	return 0;
}
