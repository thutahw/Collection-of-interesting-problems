#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

/**
 * Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

An interleaving of two strings s and t is a configuration where s and t are divided into n and m
substrings
respectively, such that:

    s = s1 + s2 + ... + sn
    t = t1 + t2 + ... + tm
    |n - m| <= 1
    The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...


Memoization Approach:
O(nm)

*/


using namespace std;

bool solve(string &s1, string &s2, string &s3, int i1, int i2, vector<vector<int>>& dp)
{
    if (i1 + i2 == s3.size()) {  // base case: finished all strings
        return true;
    }
    if (dp[i1][i2] != -1) {   // caching to avoid computing the same value again
        return dp[i1][i2];
    }

    bool ans = false;  

    if (i1 < s1.size() && s1[i1] == s3[i1 + i2]) {
        ans = (ans | solve(s1, s2, s3, i1 + 1, i2, dp));  // bitwise OR operation to retain previous true value and to combine the results of 2 recursive calls
    }

    if (i2 < s2.size() && s2[i2] == s3[i1 + i2]) {
        ans = (ans | solve(s1, s2, s3, i1, i2 + 1, dp));
    }

    return dp[i1][i2] = ans;
}

bool isInterleave(string s1, string s2, string s3) {

    if (s1.size() + s2.size() != s3.size()) {
        return false;
    }
    vector<vector<int>>dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));

    return solve(s1,s2,s3,0,0,dp);
    
}

int main() {

    cout << isInterleave("aabcc","dbbca", "aadbbcbcac") << endl;
    return 0;
}