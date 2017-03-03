#!/usr/bin/python

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if len(nums) <= 1:
        	return False
        buff_dict = {}
        for i in range(len(nums)):
        	if nums[i] in buff_dict:
        		return [buff_dict[nums[i]], i]
        	else:
        		buff_dict[target-nums[i]] = i


if __name__=='__main__':
    solution = Solution()
    # nums = [2,9,7,11]
    # target = 9
    nums = [3,2,4]
    target = 6
    print solution.twoSum(nums, target)