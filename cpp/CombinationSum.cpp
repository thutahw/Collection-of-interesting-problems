#include<iostream>
#include<vector>
/**
 * Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. 
 * You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
*/

using namespace std;

void comb(int start,vector<int>& nums,vector<int>& v,vector<vector<int>>&ans,int target) {
    if(target == 0){
        ans.push_back(v);
    }
    if(target < 0) {
        return;
    }
    for(int i = start; i < nums.size(); i++) {
        v.push_back(nums[i]);
        comb(i,nums,v,ans,target-nums[i]);
        v.pop_back(); // to reset v;
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int> v;
    comb(0,candidates,v,ans,target);
    return ans;
}

int main() {
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    vector<vector<int>> result = combinationSum(candidates, target);
    for (auto n : result) {
        for (auto x : n) {
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}