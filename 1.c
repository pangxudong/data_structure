#include <stdio.h>
#include <stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int i,j;
    int *res = malloc(sizeof(int)*2);
    for (i=0; i<numsSize; i++) {
        for (j=i+1; j<numsSize; j++) {
        	if (nums[i]+nums[j] == target) {
        		res[0] = i;
        		res[1] = j;
        		return res;
        	}
        }
    }
    return res;
}

int main() {
	int nums[] = {2, 9, 7, 15};
	int target = 9;
	int numsSize = 4;
	int* res;
	res = twoSum(nums, numsSize, target);
	printf("%d %d\n",res[0],res[1]);
	free(res);
	// printf("%d\n",twoSum(nums, numsSize, target)[1]);

	return 0;
}