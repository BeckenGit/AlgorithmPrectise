#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	char* tStr = "6,2,8,0,4,7,9,null,null,3,5";
	struct TreeNode* root = CreateTreeNode(tStr);
	struct TreeNode* t1 = nodeOfVal(root, 3);
	struct TreeNode* t2 = nodeOfVal(root, 5);
	struct TreeNode* ancestor = lowestCommonAncestor(root, t1, t2);
	printf("the lowest Common Ancestor of node %d and %d is %d\n", t1 -> val, t2 -> val, ancestor -> val);
	return 0;
}
