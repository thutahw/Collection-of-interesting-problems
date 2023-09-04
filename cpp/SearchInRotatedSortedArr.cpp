#include <iostream>
#include <vector>

/*
There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) 
such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). 

For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

O(log(n)) Binary Search
*/

using namespace std;

int solve(vector<int>& nums, int target) {

    if (nums.size() == 1) {
        if (target == nums[0]) 
            return 0;
        else
            return -1;
    }

    if (nums.size() == 2) {
        if (nums[0] == target) {
            return 0;
        } else if (nums[1] == target) {
            return 1;
        } else {
            return -1;
        }
    }
    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (target == nums[mid]) {
            return mid;
        } else if (target < nums[mid]) {
            if ((target < nums[l] && nums[r] > nums[mid]) || target > nums[l]) {  // recurse left
                r = mid - 1;
            }
            else if (target < nums[l]) { // recurse right
                l = mid + 1;
            } 
            else {
                return l;
            }
        } else {  // target > nums[mid]
            if ((target > nums[r] && nums[l] < nums[mid]) || target < nums[r]) { // recurse right
                l = mid + 1;
            }
            else if (target > nums[r]) { // recurse left
                r = mid - 1;
            } 
            else {
                return r;
            }
        }
    }
    return -1;
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
