#include <stdbool.h>
//Solution: 198. House Robber
int rob(int* nums, int numsSize);

//Solution: 24. Swap Nodes in Pairs
struct ListNode* swapPairs(struct ListNode* head);

//Solution: 345. Reverse Vowels of a String
char* reverseVowels(char* s);

//Solution: 21. Merge Two Sorted Lists
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2);


//Solution: 141. Linked List Cycle
bool isInArray(struct ListNode* node, struct ListNode** nodes, int nodesSize);
bool hasCycle(struct ListNode *head);

//Solution: 121. Best Time to Buy and Sell Stock
int maxProfit(int* prices, int pricesSize);

//Solution: 70. Climbing Stairs
int climbStairs(int n);

//Solution: 83. Remove Duplicates from Sorted List
struct ListNode* deleteDuplicates(struct ListNode* head);

//Solution: 202. Happy Number
int squaresSum(int num);
bool isHappy(int n);

//Solution: 263. Ugly Number
bool isUgly(int num);

//Solution: 235. Lowest Common Ancestor of a Binary Search Tree
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p,
                                      struct TreeNode* q);
bool isExistedInTree(struct TreeNode* root, struct TreeNode* p);

//Solution: 206. Reverse Linked List
struct ListNode* reverseList(struct ListNode* head);
struct ListNode* reverseList_R(struct ListNode* head);

//Solution: 217. Contains Duplicate
bool containsDuplicate(int* nums, int numsSize);

//Solution: 169. Majority Element
//int majorityElement(int* nums, int numsSize);

//Solution: 242. Valid Anagram
bool isAnagram(char* s, char* t);

//Solution: 100. Same Tree
bool isSameTree(struct TreeNode* p, struct TreeNode* q);

//Solution: 104. Maximum Depth of Binary Tree
int maxDepth(struct TreeNode *root);

//Solution: 283. Move Zeroes
void moveZeroes(int* nums, int numsSize);

//Solution: 226. Invert Binary Tree
struct TreeNode* invertTree(struct TreeNode* root);

//Solution: 349. Intersection of Two Arrays
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int isExisted(int num, int* nums, int numsSize);


//Solution: 350. Intersection of Two Arrays II
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);

//Solution: 237. Delete Node in a Linked List
void deleteNode(struct ListNode* node);
