#include<iostream>
#include<cstdlib>
#include<vector>
#include<algorithm>
/*
Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

    0 <= a, b, c, d < n
    a, b, c, and d are distinct.
    nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

O(n^3)
*/
using namespace std;
typedef long long ll;

vector<vector<int>> solve(vector<int>& nums, int target) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    int n = nums.size();
    for (int i = 0; i < n - 3; ++i) {
        for (int j = i + 1; j < n - 2; ++j) {
            ll newT = (ll) target - (ll) nums[i] - (ll) nums[j];
            int l = j + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[l] + nums[r] < newT) {
                    l++;
                } else if (nums[l] + nums[r] > newT) {
                    r--;
                } else {
                    result.push_back({nums[i], nums[j], nums[l], nums[r]});
                    int temp1 = l, temp2 = r;
                    while (l < r && nums[l] == nums[temp1]) l++; // prevent using the same 4 numbers
                    while (l < r && nums[r] == nums[temp2]) r--; // prevent using the same 4 numbers
                }
            }
            while (j + 1 < n && nums[j] == nums[j + 1]) j++; // prevent using the same 4 numbers
        }
        while (i + 1 < n && nums[i] == nums[i + 1]) i++; // prevent using the same 4 numbers
    }
    return result;
}

int main()
{
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> vec = solve(nums, target);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++)
            cout << vec[i][j] << " ";
        cout << endl;
    }
    return 0;
}