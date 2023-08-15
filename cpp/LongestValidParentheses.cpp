#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int longestValidParentheses(string s) {
    int l = 0, r = 0, ans = 0;
    for (char i : s){
        if (i== '(') l++;
        else r++;
        if (l == r) ans = max(ans, 2*l);
        if (r > l) l = 0, r = 0;
    }
    l = 0, r = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '(') l++;
        else r++;
        if (l == r) ans = max(ans, 2*l);
        if (r < l) l = 0, r = 0;
    }
    return ans;
}

//int main() {
//    string s;
//    cin >> s;
//    cout << longestValidParentheses(s);
//    return 0;
//}
