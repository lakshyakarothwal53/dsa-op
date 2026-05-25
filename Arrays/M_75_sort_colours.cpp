/*
LeetCode 75 - Sort Colors (Dutch National Flag Problem)

Problem summary:
Given an array nums with n objects colored red (0), white (1), or blue (2), 
sort the array in-place so that objects of the same color are adjacent, 
with the colors in the order: red, white, blue.

Example:
nums = [2,0,2,1,1,0] -> [0,0,1,1,2,2]
nums = [2,0,1] -> [0,1,2]

Approach used in this implementation (Dutch National Flag / Three-way Partition):
- Use three pointers:
  - low: boundary for 0s (everything before low is 0)
  - mid: current element being processed
  - high: boundary for 2s (everything after high is 2)
- While mid <= high:
  - If nums[mid] == 0: swap with low and increment both (low++ and mid++)
  - If nums[mid] == 2: swap with high and decrement high (high--), don't increment mid yet
  - If nums[mid] == 1: just move mid forward (mid++)

Why this works:
- We partition the array into three regions: [0s | 1s | 2s]
- low pointer marks where the next 0 should go
- high pointer marks where the next 2 should go
- mid pointer explores the middle region
- When we find a 2, we don't increment mid because the swapped element from high needs to be checked

Algorithm walkthrough (nums = [2,0,2,1,1,0]):
Initial: low=0, mid=0, high=5
mid=0, nums[0]=2: swap(0,5) -> [0,0,2,1,1,2], high=4, mid stays 0
mid=0, nums[0]=0: swap(0,0) -> [0,0,2,1,1,2], low=1, mid=1
mid=1, nums[1]=0: swap(1,1) -> [0,0,2,1,1,2], low=2, mid=2
mid=2, nums[2]=2: swap(2,4) -> [0,0,1,1,2,2], high=3, mid stays 2
mid=2, nums[2]=1: mid=3
mid=3, nums[3]=1: mid=4
mid=4, mid > high, stop
Result: [0,0,1,1,2,2]

Time & Space complexity:
- Time: O(n), single pass with three pointers
- Space: O(1), in-place sorting only
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0 ;
        int n = nums.size();
        int high = n - 1;
        int mid = 0;
        while(mid <= high){
            if(nums[mid] == 0){
                swap(nums[low++],nums[mid++]);
            }
            else if(nums[mid] == 2){
                swap(nums[high--] , nums[mid]);
            }
            else mid++;
        }
    }
};