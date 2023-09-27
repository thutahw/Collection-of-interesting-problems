#include<iostream>
#include<vector>

/**
 * Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.
*/

using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> vect(2, -1);
    if (nums.size() == 0) {
        return vect;
    }

    int l = 0;
    int r = nums.size() - 1;

    while (l <= r) {
        if (nums[l] == target && nums[r] == target) {
            return {l, r};
        }
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            if (nums[r] == target) {
                if (nums[mid - 1] == target) {
                    l++;
                } else {
                    return {mid, r};
                }
            } else if (nums[l] == target) {
                if (nums[mid + 1] == target) {
                    r--;
                } else {
                    return{l, mid};
                }
            } else if (nums[mid - 1 ] == target && nums[mid + 1] == target) {
                l++;
                r--;
            } else if (nums[mid + 1] == target) {
                l = mid;
            } else if (nums[mid - 1] == target) {
                r = mid;
            } else {
                return {mid, mid};
            }
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return vect;
}

int main() {
    
    vector<int> nums1 = {5,7,7,8,8,10};
    vector<int> nums2 = {5,7,7,8,8,10};
    vector<int> nums3 = {1};
    vector<int> nums4 = {8,8,8,8,8,8};
    vector<int> nums5 = {0,0,1,1,1,2,2,3,3,3,4,4,4,4,5,5,6,6,6,8,10,10};
    int target1 = 8; 
    int target2 = 6; 
    int target3 = 1; 
    int target4 = 8;
    int target5 = 4;
    vector<int> result1 = searchRange(nums1, target1);
    cout << result1[0] << " " << result1[1] << "\n"; // 3 4

    vector<int> result2 = searchRange(nums2, target2);
    cout << result2[0] << " " << result2[1] << "\n"; // -1 -1

    vector<int> result3 = searchRange(nums3, target3);
    cout << result3[0] << " " << result3[1] << "\n"; // 0 0

    vector<int> result4 = searchRange(nums4, target4);
    cout << result4[0] << " " << result4[1] << "\n"; // 0 5
    
    vector<int> result5 = searchRange(nums5, target5);
    cout << result5[0] << " " << result5[1] << "\n"; // 10 13

    return 0;
}