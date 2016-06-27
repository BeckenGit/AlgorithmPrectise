#include <stdio.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	char* tStr = "4, 2, 7, 1, 3, 6, 9";
	struct TreeNode* root = CreateTreeNode(tStr);
	LevelOrder(root);
	root = invertTree(root);
	LevelOrder(root);
	return 0;
}
