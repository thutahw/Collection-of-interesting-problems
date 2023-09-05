#include <iostream>
#include <vector>

/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 

For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

O(log(n)) Binary Search
*/

using namespace std;

bool solve(vector<int>& nums, int target) {

    if (nums.size() == 1) {
        return target == nums[0];
    }

    if (nums.size() == 2) {
        return nums[0] == target || nums[1] == target;
    }
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (target == nums[mid]) {
            return true;
        } else if (target < nums[mid]) {
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) {  // shrink both left and right
                r--;
                l++;
            }
            else if ((target < nums[l] && nums[r] >= nums[mid]) || target > nums[l]) {  // recurse left
                r = mid - 1;
            }
            else if (target < nums[l]) { // recurse right
                l = mid + 1;
            } 
            else {
                return true;
            }
        } else {  // target > nums[mid]
            if (nums[mid] == nums[l] && nums[mid] == nums[r]) {   // shrink both left and right
                l++;
                r--;
            }
            else if ((target > nums[r] && nums[l] <= nums[mid]) || target < nums[r]) { // recurse right
                l = mid + 1;
            }
            else if (target > nums[r]) { // recurse left
                r = mid - 1;
            } 
            else {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> nums = {4,5,6,7,0,1,2};
    vector<int> nums1 = {5,1,2,3,4};
    vector<int> nums2 = {4,5,6,7,8,1,2,3};
    vector<int> nums3 = {1};
    vector<int> nums4 = {4,5,6,7,8,9,1,2,3};
    int target1 = 3; // -1
    int target2 = 0; // 4
    int target3 = 8; // 4
    int target4 = 1;
    cout << solve(nums, target1) << "\n"; // -1
    cout << solve(nums, target2) << "\n"; // 4
    cout << solve(nums2, target3) << "\n"; // 4
    cout << solve(nums3, target2) << "\n"; // -1
    cout << solve(nums1, target4) << "\n"; // 1
    cout << solve(nums4, target4) << "\n"; // 6

    return 0;
}
