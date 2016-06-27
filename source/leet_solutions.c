#include <stdio.h>
#include "leet_lib.h"

/*
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


/*
 * Solution: 283. Move Zeroes
 * Description: Given a binary tree, find its maximum depth.
 * Detail: Given an array nums, write a function to move all 0's to the end of
           it while maintaining the relative order of the non-zero elements.
 * Example: Given nums = [0, 1, 0, 3, 12], after calling your function, nums
            should be [1, 3, 12, 0, 0].
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
