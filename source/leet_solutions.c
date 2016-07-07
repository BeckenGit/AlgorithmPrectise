#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include "leet_lib.h"
#define MAXNUM 100000
/**
 * Solution: 202. Happy Number
 * Description: Write an algorithm to determine if a number is "happy".
                A happy number is a number defined by the following process:
   Starting with any positive integer, replace the number by the sum of the
   squares of its digits, and repeat the process until the number equals 1
   (where it will stay), or it loops endlessly in a cycle which does not include
   1. Those numbers for which this process ends in 1 are happy numbers.
   Example: 19 is a happy number
            1^2 + 9^2 = 82
            8^2 + 2^2 = 68
            6^2 + 8^2 = 100
            1^2 + 0^2 + 0^2 = 1
 * Author: Becken
 * Date: 2016-7-6
 */
int squaresSum(int num){
  int s = 0;
  while(num >= 1){
    s += (num % 10)*(num % 10);
    num /= 10;
  }
  return s;
}

bool isHappy(int n) {
  int containor[MAXNUM];
  int i;
  for(i = 0; i < MAXNUM; i++){
    containor[i] = -1;
  }
  int size = 0;
  while(n != 1){
    containor[size] = n;
    size++;
    n = squaresSum(n);
    i = 0;
    while(i < size){
      if(n == containor[i])
        return false;
      i++;
    }
  }
  return true;
}


/**
 * Solution: 263. Ugly Number
 * Description: Write a program to check whether a given number is an ugly number.
                Ugly numbers are positive numbers whose prime factors only include
   2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes
   another prime factor 7.
                Note that 1 is typically treated as an ugly number.
 * Author: Becken
 * Date: 2016-7-6
 */
bool isUgly(int num) {
  if(num == 0)
    return false;
  while(num%5 == 0)
    num = num / 5;
  while(num%3 == 0)
    num = num / 3;
  while(num%2 == 0)
    num = num / 2;
  return num == 1;
}
/**
 * Solution: 235. Lowest Common Ancestor of a Binary Search Tree
 * Description: Given a binary search tree (BST), find the lowest common ancestor
   (LCA) of two given nodes in the BST.
                According to the definition of LCA on Wikipedia: “The lowest
   common ancestor is defined between two nodes v and w as the lowest node in T
   that has both v and w as descendants (where we allow a node to be a descendant
   of itself).”
          _______6______
         /              \
     ___2__          ___8__
    /      \        /      \
   0       4       7       9
         /  \
        3   5
   Example: the lowest common ancestor (LCA) of nodes 2 and 8 is 6. Another
   example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of
   itself according to the LCA definition.
 * Author: Becken
 * Date: 2016-7-5
 */

bool isExistedInTree(struct TreeNode* root, struct TreeNode* p){
  if(root == NULL)
    return false;
  if(p == root || isExistedInTree(root -> left, p) || isExistedInTree(root -> right, p))
    return true;
  return false;
 }

struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p,
                                      struct TreeNode* q) {
  struct TreeNode* ancestor = root;
  if(ancestor == p || ancestor == q)
    return ancestor;
  bool pInLeft = isExistedInTree(root -> left, p);
  bool qInLeft = isExistedInTree(root -> left, q);

  if(pInLeft && !qInLeft || !pInLeft && qInLeft)
    return ancestor;
  if(pInLeft && qInLeft)
    return lowestCommonAncestor(root -> left, p, q);
  if(!pInLeft && !qInLeft)
    return lowestCommonAncestor(root -> right, p, q);
  return NULL;
}


/**
 * Solution: 206. Reverse Linked List
 * Hint: A linked list can be reversed either iteratively or recursively. Could
   you implement both?
 * Author: Becken
 * Date: 2016-7-5
 */
//iterativen method
struct ListNode* reverseList(struct ListNode* head) {
  if(head == NULL){
    return NULL;
  }
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

//recursive method
struct ListNode* reverseList_R(struct ListNode* head) {
  if(head == NULL)
    return NULL;
  if(head -> next == NULL)
    return head;
  struct ListNode* q = head;
  head = reverseList_R(head -> next);
  struct ListNode* p = head;
  while(p -> next != NULL){
    p = p -> next;
  }
  p -> next = q;
  q -> next = NULL;
  return head;
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
 * Solution: 169. Majority Element
 * Description: Given an array of size n, find the majority element. The majority
   element is the element that appears more than ⌊ n/2 ⌋ times.

                You may assume that the array is non-empty and the majority
   element always exist in the array.
 * Author: Becken
 * Date: 2016-7-1
 */
struct eleCount{
  int num;
  int count;
};
int majorityElement(int* nums, int numsSize) {

  int eleNum = 0;
  int aEle;
  struct eleCount* eleCounts = (struct eleCount*)malloc(sizeof(struct eleCount)*eleNum);
  int i;
  for(i = 0; i < numsSize; i++){
    aEle = nums[i];

    bool isExisted = false;
    int j = 0;
    while(j < eleNum){
      if(aEle == (eleCounts[j].num)){
        isExisted = true;
        (eleCounts[j].count)++;
        break;
      }
      j++;
    }

    if(!isExisted){
      eleNum++;
      eleCounts = (struct eleCount*)realloc(eleCounts, sizeof(struct eleCount)*eleNum);
      eleCounts[eleNum - 1].num = aEle;
      eleCounts[eleNum - 1].count = 1;
    }
  }

  int maxCount = 0;
  int maxEle = 0;
  i = 0;
  while(i < eleNum){
    if(eleCounts[i].count >= maxCount){
      maxCount = eleCounts[i].count;
      maxEle = eleCounts[i].num;
    }
    i++;
  }

  return maxEle;
}


/**
 * Solution: 242. Valid Anagram (Error existed)
 * Description: Given two strings s and t, write a function to determine if t is
   an anagram of s.
 * Example: s = "anagram", t = "nagaram", return true.
            s = "rat", t = "car", return false.
 * Note: You may assume the string contains only lowercase alphabets.
 * Author: Becken
 * Date: 2016-7-1
 */
bool isAnagram(char* s, char* t) {
  int sp = 0; //the pointer of string "s"
  int tp = 0; //the pointer of string "t"
  while (s[sp] != '\0') {
    tp = 0;
    while (t[tp] != '\0') {
      if(t[tp] == s[sp]) {
        t[tp] = '#';
        break;
      }
      tp++;
    }
    sp++;
  }

  tp = 0;
  while(t[tp] != '\0'){
    if(t[tp] != '#')
      return false;
    tp++;
  }
  if (sp != tp)
    return false;
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
  else if(p -> val == q -> val && isSameTree(p -> left, q -> left) &&
          isSameTree(p -> right, q ->right))
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
