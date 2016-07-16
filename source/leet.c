#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	int nums1[3] = {1, 2, 5};
	int numsSize1 = 3;
	struct ListNode* head1 = ArrayToList(nums1, numsSize1);

	int nums2[2] = {3, 4};
	int numsSize2 = 2;
	struct ListNode* head2 = ArrayToList(nums2, numsSize2);

	struct ListNode* head = mergeTwoLists(head1, head2);

	printList(head);
	return 0;
}
