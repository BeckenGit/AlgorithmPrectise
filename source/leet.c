#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	char* pStr = "1, 2, 4";
	char* qStr = "1, 2, 3";
	struct TreeNode* p = CreateTreeNode(pStr);
	struct TreeNode* q = CreateTreeNode(qStr);

	if(isSameTree(p, q))
		printf("yes!\n");
	else
		printf("No!\n");

	return 0;
}
