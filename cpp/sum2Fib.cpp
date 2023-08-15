#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

typedef long long ll;

/*
Given an integer array of positive integers, return a boolean array stating whether each number can be
represented as a sum of 2 fibonacci numbers

 1, 1, 2, 3, 5, 8, 13, 21, ...

 e.g. input: [2, 5, 17]
 output: [true, true, false]

 explanation: 2 = 1 + 1
            5 = 2 + 3
            17 cannot be represented.

Time Complexity: O(nk) where k is the largest number present and n is the size of the input array
*/

vector<bool> solution(vector<ll> a) {

    ll maxNum = *max_element(a.begin(), a.end());
    vector<bool> result(a.size(), false);
    ll x = 1;
    ll y = 2;
    ll z = x + y;
    unordered_map<ll, bool> hmap;
    hmap[x] = true;
    hmap[y] = true;
    while (z < maxNum) {   // compute fibonacci numbers with values up to maxNum - 1
        hmap[z] = true;
        y = z;
        z = z + y;
    }

    for (int i = 0; i < a.size(); i++) {
        for (const auto& key_value : hmap) {
            ll target = a[i] - key_value.first;
            if (hmap.find(target) != hmap.end()) { // exists
                if (target == key_value.first) {
                    if (target == 1) {
                        result[i] = true;
                    }
                }
                else {
                    result[i] = true;
                }
            }
        }
    }


    return result;
}

int main() {
    vector<bool> ans = solution({ 1, 2, 5, 17, 999999999 });
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << "\n";
    }
    return 0;
}

