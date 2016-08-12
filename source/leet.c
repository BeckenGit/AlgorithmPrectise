#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#include "leet_solutions.h"

int main() {
	char* s = "1,2,3";
	struct TreeNode* t = CreateTreeNode(s);
	int* returnSizeAddr = (int*)malloc(sizeof(int));
	int** columnSizesAddr = (int**)malloc(sizeof(int*));
	int** result = levelOrderBottom(t, columnSizesAddr, returnSizeAddr);
	int i, j;
	for(i = 0; i < (*returnSizeAddr); i++){
		for(j = 0; j < (*columnSizesAddr)[i]; j++)
			printf("%d ", result[i][j]);
		printf("\n");
	}

	//print
	printf("returnSize: %d\n", (*returnSizeAddr));
	return 0;
}
