#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

/**
 * Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

    Insert a character
    Delete a character
    Replace a character

O(l1)(l2)

*/

using namespace std;

int minDistance(string word1, string word2) {
    int l1 = word1.length();
    int l2 = word2.length();

    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));

    for (int i = 0; i <= l1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= l2; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i <= l1; i++) {
        for (int j = 1; j <= l2; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
            }
        }
    }

    return dp[l1][l2];
}

int main() {

    cout << minDistance("horse", "ros") << endl;
    return 0;
}