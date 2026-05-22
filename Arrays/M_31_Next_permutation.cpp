/*
LeetCode 31 - Next Permutation

Problem summary:
Given an array of integers, rearrange it into the next lexicographically greater permutation.
If no such permutation exists (array is in descending order), rearrange it to the smallest permutation (ascending order).
Modify the array in-place.

Example:
[1,2,3] -> [1,3,2]
[3,2,1] -> [1,2,3]
[1,1,5] -> [1,5,1]

Approach used in this implementation (3-step algorithm):
1. Find the pivot: Starting from the right, find the first index i where nums[i] < nums[i+1].
   This is the rightmost position where the ascending order breaks.
2. If pivot exists: Find the smallest element to the right of pivot that is greater than nums[pivot].
   Swap them.
3. Reverse: Reverse the suffix starting from pivot+1 to get the next smallest permutation.

Why this works:
- The pivot divides the array into two parts: left part (to be modified) and right part (in descending order).
- By swapping with the next larger element and reversing the suffix, we get the next lexicographically greater permutation.
- If no pivot is found, the entire array is in descending order, so we reverse it to get the smallest permutation.

Example walkthrough:
[1,3,2] -> [1,2,3]
- Pivot at index 0 (1 < 3)
- Find smallest greater than 1 from right: 2
- Swap: [2,3,1]
- Reverse from index 1: [2,1,3]

Time & Space complexity:
- Time: O(n), single pass to find pivot + O(n) to find swap element + O(n) reverse.
- Space: O(1), in-place modification only.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() - 1;
        int pivot = -1;
        for(int i = n - 1; i >= 0 ; i--){
            if(nums[i + 1] > nums[i]){
                pivot = i;
                break;
            }
        }
        if(pivot != -1) {
                for(int j = n ; j > pivot ; j--){
                    if(nums[j] > nums[pivot]) {
                        swap(nums[pivot],nums[j]);
                        break;
                    }
                }
            }
        reverse(nums.begin() + pivot + 1 , nums.end());   
    }
};