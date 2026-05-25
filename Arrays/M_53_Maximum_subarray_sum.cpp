/*
LeetCode 53 - Maximum Subarray Sum (Kadane's Algorithm)

Problem summary:
Given an integer array nums, find the contiguous subarray (containing at least one number) 
which has the largest sum and return that sum.

Example:
nums = [-2,1,-3,4,-1,2,1,-5,4] -> Output: 6 (subarray [4,-1,2,1])
nums = [-1] -> Output: -1
nums = [5,4,-1,7,8] -> Output: 23 (entire array)

Approach used in this implementation (Kadane's Algorithm):
- Use two variables:
  - csum (current sum): tracks the maximum sum ending at the current position
  - msum (max sum): tracks the overall maximum sum found so far
- For each element:
  - Add it to csum: csum += nums[i]
  - Update msum if csum is greater: msum = max(csum, msum)
  - If csum becomes negative, reset it to 0 (start fresh from the next element)
- Return msum, the maximum sum found

Why this works:
- At each position, we decide: either extend the current subarray or start a new one.
- If the current sum becomes negative, it's better to start fresh because negative sums only decrease future sums.
- By keeping track of msum, we capture the best sum seen at any point.

Algorithm walkthrough (nums = [-2,1,-3,4,-1,2,1,-5,4]):
i=0: csum=-2, msum=-2, csum<0 -> csum=0
i=1: csum=1, msum=1
i=2: csum=-2, msum=1, csum<0 -> csum=0
i=3: csum=4, msum=4
i=4: csum=3, msum=4
i=5: csum=5, msum=5
i=6: csum=6, msum=6
i=7: csum=1, msum=6
i=8: csum=5, msum=6
Result: 6

Time & Space complexity:
- Time: O(n), single pass through the array
- Space: O(1), only using two variables
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int msum = INT_MIN;
        int csum = 0;
        for(int i = 0 ; i < n ; i++) {
            csum+=nums[i];
            msum = max(csum , msum);
            if(csum < 0){
                csum = 0;
            }    
        }
        return msum;
    }
};