#include<stdio.h>
#include<malloc.h>
int* sort_bubble(int* nums, int numsSize);
int* num2digital(int num, int* numSize);
int main(){
  int num = 29475;
  int* numSize = (int*)malloc(sizeof(int));
  int* digitals;
  digitals = num2digital(num, numSize);
  int i;
  for(i = 0; i < *numSize; i++){
    printf("%d ",digitals[i]);
  }
  printf("\n");

  digitals = sort_bubble(digitals, *numSize);
  for(i = 0; i < *numSize; i++){
    printf("%d ",digitals[i]);
  }
  printf("\n");
  return 0;
}

int* num2digital(int num, int* numSize){
  *numSize = 0;
  int* digitals = (int*)malloc(sizeof(int)*(*numSize));
  while(num > 0){
    (*numSize)++;
    digitals = (int*)realloc(digitals, (*numSize)*sizeof(int));
    digitals[*numSize - 1] = num % 10;
    num/=10;
  }
  return digitals;
}

int* sort_bubble(int* nums, int numsSize){
  int i, j, temp;
  for(i = numsSize - 1; i >= 1; i--)
    for(j = 0; j < i; j++)
      if(nums[j] < nums[j + 1]){
        temp = nums[j];
        nums[j] = nums[j + 1];
        nums[j + 1] = temp;
      }
  return nums;
}
