#include<bits/stdc++.h>

/*
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.
O(n^2)
*/
using namespace std;

int solve(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int min_difference = INT_MAX;
    int result = 0;
    for (int i = 0; i < nums.size(); ++i) {
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            int currSum = nums[i] + nums[l] + nums[r];
            if (abs(target - currSum) < min_difference) {
                min_difference = abs(target - currSum);
                result = currSum;
            }
            if (currSum == target) {
                return result;
            }
            if (currSum > target) {
                r--;
            } else {
                l++;
            }
            
        }
    }
    return result;
}

int main() {

    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    cout << solve(nums, target) << endl;
    return 0;
}