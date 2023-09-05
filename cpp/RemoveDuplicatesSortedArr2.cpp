#include<iostream>
#include<vector>

using namespace std;

int solve(vector<int>& nums) {
    int n = nums.size();
    int k = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            nums[k] = nums[i];
            count++;
            k++;
            continue;
        }
        if (nums[i] == nums[i - 1]) {
            if (count < 2) {
                nums[k] = nums[i];
                k++;
                count++;
            }
        } else {
            nums[k] = nums[i];
            k++;
            count = 1;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> nums1 = {0,0,1,1,1,1,2,3,3};
    cout << solve(nums) << "\n"; // 5
    cout << solve(nums1) << "\n"; // 5
    return 0;
}