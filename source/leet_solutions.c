#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#define MAXNUM 100000
/**
 * Solution: 206. Reverse Linked List
 * Hint: A linked list can be reversed either iteratively or recursively. Could
   you implement both?
 * Author: Becken
 * Date: 2016-7-4
 */
struct ListNode* reverseList(struct ListNode* head) {
  struct ListNode* p = head;
  struct ListNode* q;
  struct ListNode* tail;
  while(p -> next != NULL){
    p = p -> next;
  }
  tail = p;

  p = head;
  while(p != tail){
    q = p;
    p = p -> next;
    q -> next = tail -> next;
    tail -> next = q;
  }
  return tail;
}


/**
 * Solution: 217. Contains Duplicate
 * Description: Given an array of integers, find if the array contains any
   duplicates. Your function should return true if any value appears at least
   twice in the array, and it should return false if every element is distinct.
 * Author: Becken
 * Date: 2016-7-4
 */
bool containsDuplicate(int* nums, int numsSize) {
  int i, j;
  for(i = 0; i < numsSize - 1; i++){
    for(j = i + 1; j < numsSize; j++){
      if(nums[i] == nums[j])
        return true;
    }
  }
  return false;
}

/**
 * Solution: 242. Valid Anagram
 * Description: Given two strings s and t, write a function to determine if t is
   an anagram of s.
 * Example: s = "anagram", t = "nagaram", return true.
            s = "rat", t = "car", return false.
 * Note: You may assume the string contains only lowercase alphabets.
 * Author: Becken
 * Date: 2016-6-30
 */
bool isAnagram(char* s, char* t) {
  return true;
}


/**
 * Solution: 100. Same Tree
 * Description: Given two binary trees, write a function to check if they are
   equal or not.Two binary trees are considered equal if they are structurally
   identical and the nodes have the same value.
 * Author: Becken
 * Date: 2016-6-30
 */
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
  if(p == NULL && q == NULL)
    return true;
  else if(p == NULL || q == NULL)
    return false;
  else if(p -> val == q -> val && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q ->right))
    return true;
  else
    return false;
}


/**
 * Solution: 237. Delete Node in a Linked List
 * Description: Write a function to delete a node (except the tail) in a singly
   linked list, given only access to that node.
 * Example: Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the
   third node with value 3, the linked list should become 1 -> 2 -> 4 after
   calling your function.
 * Author: Becken
 * Date: 2016-6-28
 */
void deleteNode(struct ListNode* node) {
  while(node -> next != NULL){
    node -> val = node -> next -> val;
    if(node -> next -> next == NULL)
      break;
    node = node -> next;
  }
  node -> next = NULL;
}


/**
 * Solution: 104. Maximum Depth of Binary Tree
 * Description: Given a binary tree, find its maximum depth.
 * Detail: The maximum depth is the number of nodes along the longest path from
   the root node down to the farthest leaf node.
 * Author: Becken
 * Date: 2016-6-26
 */
int maxDepth(struct TreeNode *root){
  if(root == NULL)
    return 0;
	int leftMaxDepth = maxDepth(root->left);
	int rightMaxDepth = maxDepth(root->right);
  if(leftMaxDepth > rightMaxDepth)
    return leftMaxDepth + 1;
  else
    return rightMaxDepth + 1;
}


/**
 * Solution: 283. Move Zeroes
 * Description: Given a binary tree, find its maximum depth.
 * Detail: Given an array nums, write a function to move all 0's to the end of
   it while maintaining the relative order of the non-zero elements.
 * Example: Given nums = [0, 1, 0, 3, 12], after calling your function, nums
   should be [1, 3, 12, 0, 0].
 * Author: Becken
 * Date: 2016-6-26
 */
 void moveZeroes(int* nums, int numsSize) {
   int nextNonZero = 0;

   int i;
   for(i = 0; i < numsSize; i++){
     if(nums[i] != 0){
       if(i != nextNonZero){
         nums[nextNonZero] = nums[i];
         nums[i] = 0;
       }
       nextNonZero++;
     }
   }
 }


 /**
  * Solution: 226. Invert Binary Tree
  * Description: Invert a binary tree.
        4
      /   \
     2     7
    / \   / \
   1   3 6   9
   to
        4
      /   \
     7     2
    / \   / \
   9   6 3   1
  * Author: Becken
  * Date: 2016-6-27
  */
struct TreeNode* invertTree(struct TreeNode* root) {
  if(root != NULL){
    struct TreeNode* tTemp;
    tTemp = root -> left;
    root -> left = root -> right;
    root -> right = tTemp;
    invertTree(root -> left);
    invertTree(root -> right);
  }
  return root;
}


/**
 * Solution: 349. Intersection of Two Arrays
 * Description: Given two arrays, write a function to compute their intersection.
 * Example: Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * Note: 1. Each element in the result must be unique.
         2. The result can be in any order.
 * Author: Becken
 * Date: 2016-6-27
 */

int isExisted(int num, int* nums, int numsSize){
  int i;
  for(i = 0; i < numsSize; i++){
    if(num == nums[i])
      return 1;
  }
  return 0;
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int i;
  *returnSize = 0;
  int* returnNums = (int*)malloc(sizeof(int)*(*returnSize));
  for(i = 0; i < nums1Size; i++){
    if(isExisted(nums1[i], nums2, nums2Size) && !isExisted(nums1[i], returnNums, *returnSize)){
      (*returnSize)++;
      returnNums = (int*)realloc(returnNums, sizeof(int)*(*returnSize));
      returnNums[*returnSize - 1] = nums1[i];
    }
  }
  return returnNums;
}


/**
 * Solution: 350. Intersection of Two Arrays II
 * Description: Given two arrays, write a function to compute their intersection.
 * Example: Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
 * Note: 1. Each element in the result should appear as many times as it shows
   in both arrays.
         2. The result can be in any order.
 * Author: Becken
 * Date: 2016-6-28
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
  int i, j;
  int num_index_ij[MAXNUM][2];
  for(i = 0; i < MAXNUM; i++){
    num_index_ij[i][0] = -1;
    num_index_ij[i][1] = -1;
  }
  *returnSize = 0;
  int* returnNums = (int*)malloc(sizeof(int)*(*returnSize));
  for(i = 0; i < nums1Size; i++){
    for(j = 0; j < nums2Size; j++){
      if(nums1[i] == nums2[j] && i > num_index_ij[nums1[i]][0] && j > num_index_ij[nums1[i]][1]){
        (*returnSize)++;
        returnNums = (int*)realloc(returnNums, sizeof(int)*(*returnSize));
        returnNums[*returnSize - 1] = nums1[i];
        num_index_ij[nums1[i]][0] = i;
        num_index_ij[nums1[i]][1] = j;
      }
    }
  }
  return returnNums;
}
