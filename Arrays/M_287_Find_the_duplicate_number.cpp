/*
LeetCode 287 - Find the Duplicate Number

Problem summary:
Given an array nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, but it may be repeated more than once.
Find the duplicate number without modifying the array and using only O(1) extra space.

Constraints: Cannot use extra space (except a few variables), cannot modify the array (in this approach it gets modified).

Example:
nums = [1,3,4,2,2] -> Output: 2
nums = [3,1,3,4,2] -> Output: 3
nums = [1,4,4,2,4] -> Output: 4

Approach used in this implementation (Mark visited using sign):
- Use the array values as indices (since values are in range [1, n] and indices are [0, n])
- Use the sign of elements to mark if a number has been visited
- For each number, take its absolute value to get the index, then mark that index as visited by negating it
- When we find an index that is already negative, it means the value (index + 1) is a duplicate
- The duplicate is found at the position where we encounter a negative number

Why this works:
- Values range from 1 to n, so abs(value) - 1 gives us a valid index in [0, n-1]
- We can't use a separate visited array, so we use the sign of elements as a marker
- When a value points to an index that's already negative, it's the second time we're seeing that number
- The algorithm finds the duplicate number itself, not just that one exists

Algorithm walkthrough (nums = [1,3,4,2,2]):
Initial: nums = [1,3,4,2,2]
i=0: abs(1)-1=0, nums[0]=1 > 0, mark nums[0]=-1, nums=[-1,3,4,2,2], i=1
i=1: abs(3)-1=2, nums[2]=4 > 0, mark nums[2]=-4, nums=[-1,3,-4,2,2], i=2
i=2: abs(-4)-1=3, nums[3]=2 > 0, mark nums[3]=-2, nums=[-1,3,-4,-2,2], i=3
i=3: abs(-2)-1=1, nums[1]=3 > 0, mark nums[1]=-3, nums=[-1,-3,-4,-2,2], i=4
i=4: abs(2)-1=1, nums[1]=-3 < 0 (already visited!), loop breaks
Return: abs(nums[4]) = abs(2) = 2 (the duplicate)

Time & Space complexity:
- Time: O(n), single pass through the array
- Space: O(1), using only a few variables (modifies input array)

NOTE: This solution modifies the input array. A non-modifying approach uses Floyd's Cycle Detection (tortoise and hare).
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i = 0;
        while(i < nums.size() && nums[abs(nums[i]) - 1] > 0){
            nums[abs(nums[i]) - 1] *= -1;
            i++;
        }
        return abs(nums[i]);
    }
};