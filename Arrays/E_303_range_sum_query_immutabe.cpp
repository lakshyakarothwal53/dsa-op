class NumArray {
public:
int pref[10000];
    NumArray(vector<int>& nums) {
        pref[0] = nums[0];
        for(int i = 1 ; i < nums.size() ; i++ ) {
            pref[i] = nums[i] + pref[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return left != 0 ? pref[right] - pref[left - 1] : pref[right];
    }
};
/*
LeetCode 303 - Range Sum Query - Immutable

Problem summary:
Given an integer array nums, design a data structure that can quickly return the sum of the elements of nums between indices left and right (inclusive).

Approach used in this implementation:
- Build a prefix-sum array `pref` where pref[i] stores the sum of nums[0..i].
- To answer sumRange(left, right): return pref[right] - pref[left-1] when left > 0, otherwise pref[right] when left == 0.

Why this works:
- pref[right] is sum(nums[0..right]). Removing sum(nums[0..left-1]) yields sum(nums[left..right]).

Time & Space complexity:
- Preprocessing (constructor): O(n) time to build the prefix array and O(n) space for `pref`.
- Query (sumRange): O(1) time per query.

Edge cases / notes:
- This implementation assumes `nums` is non-empty and that `pref` has enough capacity for the input size.
    In production code, prefer using a std::vector<long long> for prefix sums to avoid fixed-size arrays and integer overflow on large inputs.
- If nums can be empty, guard the constructor accordingly.

Example:
nums = [1, 2, 3, 4]
pref = [1, 3, 6, 10]
sumRange(1, 3) = pref[3] - pref[0] = 10 - 1 = 9 (which is 2+3+4)
*/