#include<bits/stdc++.h>

/**
 * You are given a list of unique integers nums. Return the number of integers that could still be successfully found using a standard binary search.

Binary search in pseudocode:

lo = 0
hi = nums.size - 1

while lo <= hi
    mid = floor((lo + hi) / 2)
    if nums[mid] == target
        return mid
    elif nums[mid] < target
        lo = mid + 1
    else
        hi = mid - 1

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums.

Example 1

Input

nums = [1, 5, 3, 2, 9]

Output

3

Explanation

Since if we used binary search to look for 3, we would still find it in the first iteration. We would also 
happen to find 1 and 9 after two iterations.

T(n) = 2T(n/2) + O(1)

=>O(N)
*/

using namespace std;

int evaluate(vector<int>& nums, int l, int h, int a, int b) {
    if (l > h) {
        return 0;
    } 
    auto m = (l + h) / 2;
    auto mid = nums[m];
    return int(a <= mid && mid <= b) + evaluate(nums, l, m - 1, a, min(mid - 1, b)) // update next biggest
                + evaluate(nums, m + 1, h, max(a, mid + 1), b); // update next smallest
}

int solve(vector<int>& nums) {
    return evaluate(nums, 0, (int) nums.size() - 1, INT_MIN, INT_MAX);
}


int main() {
    vector<int> arr1 = {1, 5, 3, 2, 9};  // 3
    cout << solve(arr1) << "\n";
    return 0;

}