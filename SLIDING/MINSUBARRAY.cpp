/*
 Given an array of positive integers nums and a positive integer target, return the minimal length of a
subarray
whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 

Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.
Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1
Example 3:

Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
 

Constraints:

1 <= target <= 109
1 <= nums.length <= 105
*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int win = INT_MAX; //minimum length subarray
        int l = 0;
        int r = 0;
        int add = 0;
        while(r<nums.size()){
            add += nums[r];
            while(add>=target){ //expanison->when invalid case intially
                win = min(win,r-l+1);
                add -= nums[l];
                l++;
            }
            r ++;
            
        }
        if(win == INT_MAX){
            return 0;
        }
        return win;
    }
};
