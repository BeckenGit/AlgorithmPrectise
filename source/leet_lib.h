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

//Definition for singly-linked list.
struct ListNode {
  int val;
  struct ListNode *next;
};
struct ListNode* listNodeOfVal(struct ListNode* head, int val);
struct TreeNode* treeNodeOfVal(struct TreeNode* root, int val);
struct ListNode* ArrayToList(int* nums, int numsSize);
struct TreeNode* CreateTreeNode(char* str);
void PreOrder(struct TreeNode* root);
void LevelOrder(struct TreeNode* root);
void printArray(int* nums, int numsSize);
void printList(struct ListNode* head);

#endif
