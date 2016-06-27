#include <stdio.h>
#include "leet_lib.h"
#include <malloc.h>

struct TreeNode* CreateTreeNode(char* str) {
	if (str[0] == '\0')
		return NULL;
	//define a queue
	struct TreeNode* queue[MAXSIZE];
	int front=0,rear = 0;

	struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	struct TreeNode* parentNode;
	int strIndex = 0;
	int strValIndex = 0;
	char* strVal= (char*)malloc(MAXSTR*sizeof(char));
	while (str[strIndex] != '\0' && str[strIndex] != ',') {
		strVal[strValIndex] = str[strIndex];
		strValIndex++;
		strIndex++;
	}
	strVal[strValIndex] = '\0';
	sscanf(strVal, "%d", &root->val);
	rear = (rear + 1) % MAXSIZE;
	queue[rear] = root;

	while (front!=rear) {
		front = (front + 1) % MAXSIZE;
		parentNode = queue[front];

		//create left node
		if (str[strIndex] == '\0')
			parentNode->left = NULL;
		else {
			strValIndex = 0;
			strIndex++;
			while (str[strIndex] != ',' && str[strIndex] != '\0') {
				strVal[strValIndex] = str[strIndex];
				strValIndex++;
				strIndex++;
			}
			strVal[strValIndex] = '\0';
			if (strVal[strValIndex - 1] == 'l') {
				parentNode->left = NULL;
			}
			else {
				struct TreeNode* leftNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
				sscanf(strVal, "%d", &leftNode->val);
				parentNode->left = leftNode;

				rear = (rear + 1) % MAXSIZE;
				queue[rear] = leftNode;
			}
		}

		//create right node
		if (str[strIndex] == '\0')
			parentNode->right = NULL;
		else {
			strValIndex = 0;
			strIndex++;
			while (str[strIndex] != ',' && str[strIndex] != '\0') {
				strVal[strValIndex] = str[strIndex];
				strValIndex++;
				strIndex++;
			}
			strVal[strValIndex] = '\0';
			if (strVal[strValIndex - 1] == 'l') {
				parentNode->right = NULL;
			}
			else {
				struct TreeNode* rightNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
				sscanf(strVal, "%d", &rightNode->val);
				parentNode->right = rightNode;

				rear = (rear + 1) % MAXSIZE;
				queue[rear] = rightNode;
			}
		}
	}
	return root;
}

void PreOrder(struct TreeNode* root) {
	struct TreeNode* stack[MAXSIZE];
	struct TreeNode* t;
	int top = -1;

	if (root != NULL) {
		top++;
		stack[top] = root;
		while (top != -1) {
			t = stack[top];
			top--;
			printf("%d ", t->val);

			if (t->right != NULL) {
				top++;
				stack[top] = t->right;
			}
			if (t->left != NULL) {
				top++;
				stack[top] = t->left;
			}
		}
		printf("\n");
	}
}

void LevelOrder(struct TreeNode* root) {
	if (root != NULL) {
		struct TreeNode* queue[MAXSIZE];
		int rear = 0, front = 0;

		rear = (rear + 1) % MAXSIZE;
		queue[rear] = root;
		struct TreeNode* t;
		while (rear != front) {
			front = (front + 1) % MAXSIZE;
			t = queue[front];
			printf("%d ", t->val);

			if (t->left != NULL) {
				rear = (rear + 1) % MAXSIZE;
				queue[rear] = t->left;
			}
			if (t->right != NULL) {
				rear = (rear + 1) % MAXSIZE;
				queue[rear] = t->right;
			}
		}
		printf("\n");
	}
}

void printArray(int* nums, int numsSize){
	printf("Num: ");
	int i;
	for(i = 0; i < numsSize; i++){
		printf("%d ",nums[i]);
	}
	printf("\n");
}
