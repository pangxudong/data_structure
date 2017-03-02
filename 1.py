#!/usr/bin/python

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        numsSize = len(nums)
        for i in range(0,numsSize):
        	for j in range(i+1,numsSize):
        		if(nums[i]+nums[j]==target):
        			return [i,j]
        return []


if __name__=='__main__':
    solution = Solution()
    # nums = [2,9,7,11]
    # target = 9
    nums = [3,2,4]
    target = 6
    print solution.twoSum(nums, target)