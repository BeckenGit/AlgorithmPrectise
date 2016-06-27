//Tree data struct definition
#ifndef LEET_LIB_H
#define LEET_LIB_H

#define MAXSIZE 1000
#define MAXSTR 10
struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
};
struct TreeNode* CreateTreeNode(char* str);
void PreOrder(struct TreeNode* root);
void LevelOrder(struct TreeNode* root);
void printArray(int* nums, int numsSize);

#endif
