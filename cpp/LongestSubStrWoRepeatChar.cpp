#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
/**
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * O(n) approach using sliding window technique with character array.
*/
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int maxLen = 0;
    vector<int> charArr(128, -1);
    int l = 0;

    for (int r = 0; r < n; r++) {
        if (charArr[s[r]] >= l) { // repeating character
            l = charArr[s[r]] + 1;
        }
        charArr[s[r]] = r;
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;

}


int main() {
    cout << lengthOfLongestSubstring("aaaaa") << "\n"; // 1
    cout << lengthOfLongestSubstring("abcabcbb") << "\n"; // 3
    cout << lengthOfLongestSubstring("pwwkew") << "\n"; // 3
    return 0;
}