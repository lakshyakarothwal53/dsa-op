/*
LeetCode 169 - Majority Element

Problem summary:
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than n/2 times.
You may assume that the majority element always exists in the array.

Example:
nums = [3,2,3] -> Output: 3 (3 appears 2 times, which is > 3/2 = 1.5)
nums = [2,2,1,1,1,2,2] -> Output: 2 (2 appears 4 times, which is > 7/2 = 3.5)
nums = [1] -> Output: 1

Approach used in this implementation (Boyer-Moore Voting Algorithm):
This is an elegant O(n) time and O(1) space algorithm that finds the majority element.

Key insight:
- The majority element appears more than n/2 times
- If we pair up each majority element with a different element and cancel them out,
  the majority element will still have votes left

Algorithm:
- Maintain two variables:
  - ans: the current candidate for majority element
  - count: the count of how many times the current candidate appears consecutively
- For each element in the array:
  - If element == ans: increment count
  - Else if count == 0: current candidate has no votes left, replace with new element (ans = nums[i], count = 1)
  - Else: decrement count (cancel out the current candidate and the different element)
- After one pass, ans will be the majority element

Why this works:
- By the voting principle, if we "vote out" all non-majority elements against the majority element,
  the majority element will always have remaining votes
- The majority element appears > n/2 times, so it always survives

Algorithm walkthrough (nums = [2,2,1,1,1,2,2]):
Initial: ans = 2, count = 0

i=0: nums[0]=2, 2==2, count=1
i=1: nums[1]=2, 2==2, count=2
i=2: nums[2]=1, 1!=2 and count!=0, count=1 (cancel out one 2 and one 1)
i=3: nums[3]=1, 1!=2 and count!=0, count=0 (cancel out one 2 and one 1)
i=4: nums[4]=1, 1!=2 and count==0, ans=1, count=1 (new candidate)
i=5: nums[5]=2, 2!=1 and count!=0, count=0 (cancel out one 1 and one 2)
i=6: nums[6]=2, 2!=1 and count==0, ans=2, count=1 (new candidate)

Final: ans = 2 (the majority element)

Visual (pairing and canceling):
[2, 2, 1, 1, 1, 2, 2]
[2] vs [1,1] -> remaining: [2] (ans=2)
[2] vs [1,1] -> no more pairs, ans=2, count=1
[2] vs [2] -> they're the same, count becomes 2
Result: 2 is the majority

Time & Space complexity:
- Time: O(n), single pass through the array
- Space: O(1), only using two variables

Note: There's a bug in the provided code at line "count == 1;" which should be "count = 1;"
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = nums[0];
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == ans)
                count++;
            else if (count == 0) {
                count == 1;
                ans = nums[i];
            } else
                count--;
        }

        return ans;
    }
};