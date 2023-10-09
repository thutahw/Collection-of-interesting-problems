#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
/**
 * Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.
*/
using namespace std;

void comb(int start,vector<int>& nums,vector<int>& v,vector<vector<int>>&ans,int target, int sum) {
    if(target == sum){
        ans.push_back(v);
    }
    if(target < sum) {
        return;
    }
    for(int i = start; i < nums.size(); i++) {
        if(i != start && nums[i] == nums[i-1]) {  //to avoid picking up the same combnations
            continue;
        }
        sum += nums[i];
        v.push_back(nums[i]);
        comb(i + 1,nums,v,ans,target, sum);
        sum -= nums[i];
        v.pop_back(); // to reset v;
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>>ans;
    vector<int> v;
    sort(candidates.begin(), candidates.end());
    comb(0,candidates,v,ans,target,0);
    return ans;    
}

int main() {
    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> result = combinationSum2(candidates, target);
    for (auto n : result) {
        for (auto x : n) {
            cout << x << " ";
        }
        cout << "\n";
    }
    
    return 0;
}