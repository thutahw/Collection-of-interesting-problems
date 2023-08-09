#include<bits/stdc++.h>

/**
 * You are given a list of integers seats containing 1s and 0s. 
Each element seats[i] represents a seat and is either occupied if seats[i] = 1 or empty if seats[i] = 0.

Given that there’s at least one empty seat and at least one occupied seat, return the maximum distance from an empty seat to the closest occupied seat.

Constraints

n ≤ 100,000 where n is the length of seats
------------------------------------------------------------------
Example 1

Input

seats = [1, 0, 1, 0, 0, 0, 1]

Output

2

Explanation

We can sit at seats[4].
-------------------------------------------------------------------
Example 2

Input

seats = [1, 0, 0, 0]

Output

3

Explanation

We can sit at seats[3].
*/

using namespace std;

int solve(vector<int>& arr) {
    vector<int> occPos;
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == 1) {
            occPos.push_back(i);
        }
    }
    int size = occPos.size();
    int start = 0;
    vector<int> dist(arr.size(), 0);
    for (int j = 0; j < arr.size(); ++j) {
        if (arr[j] == 0) {
            dist[j] = j - occPos[start];
            if (start < size - 1 && occPos[start + 1] - j <= dist[j]) {  // has next occupied seat and it is closer
                start++;
                dist[j] = occPos[start] - j;
            }
        }
    }
    return *max_element(dist.begin(), dist.end());
}

int main() {
    vector<int> arr1 = {1, 0, 1, 0, 0, 0, 1};  // 2
    vector<int> arr2 = {1, 0, 0, 0}; // 3
    cout << solve(arr1) << "\n";
    cout << solve(arr2) << "\n";
    return 0;
}
