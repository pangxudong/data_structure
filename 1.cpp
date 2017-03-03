#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> res;
        for(int i=0; i<nums.size(); i++) {
        	for (int j=i+1; j<nums.size(); j++) {
        		if (nums[i]+nums[j] == target) {
        			res.push_back(i);
        			res.push_back(j);
        			return res;
        		}
        	}
        }
        return res;
    }
};


int main() {
	int nums_row[4] = {2,7,9,15};
	vector<int> nums(nums_row, nums_row+4);
	int target = 9;
	Solution solution;
	vector<int> path =  solution.twoSum(nums, target);
	for (std::vector<int>::const_iterator i = path.begin(); i != path.end(); ++i) {
		std::cout << *i << ' ';
	}
	return 0;
}