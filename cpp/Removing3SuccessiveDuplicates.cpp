#include<bits/stdc++.h>
/*
Given a string s containing "0"s and "1"s, consider an operation where you pick a character and toggle its value from "0" to "1" or from "1" to "0". 
Return the minimum number of operations required to obtain a string containing no instances of three identical consecutive characters.

Constraints

0 ≤ n ≤ 100,000 where n is the length of s

Example 1

Input

s = "1100011"

Output

1

Explanation

We can toggle the middle "0" to a "1".


Example 2

Input

s = "0001000"

Output

2

Explanation

We can toggle the first and the last characters to get "1001001"

O(n)
*/
using namespace std;

int solve(string s) {
	int ans = 0;
	for (int i = 0; i < s.size();) {
		int j = i + 1;
		while (j < s.size() && s[i] == s[j]) {
			j++;
		}
		ans += (j - i) / 3;
		i = j;
	}
	return ans;
}

int main() {
	string s;
	cin >> s;
	cout << solve(s) << endl;
	return 0;
}