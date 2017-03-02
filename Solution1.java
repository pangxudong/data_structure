import java.util.Arrays;

public class Solution1 {
    public int[] twoSum(int[] nums, int target) {
        int[] a = new int[2];
        for (int i=0; i<nums.length; i++) {
        	for (int j = i+1; j<nums.length; j++) {
        		if (nums[i]+nums[j] == target) {
        			a[0] = i;
        			a[1] = j;
        			return a;
        		}
        	}
        }
        return a;
    }

    public static void  main(String[] args) {
    	Solution1 solution = new Solution1();
    	int[] nums = new int[]{2,7,9,11};
    	int target = 9;
    	System.out.println(Arrays.toString(solution.twoSum(nums, target)));
    }
}