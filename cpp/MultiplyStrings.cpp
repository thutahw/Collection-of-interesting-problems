#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
/**
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.

Approach: shoe-lace technique
*/
using namespace std;

string multiply(string a, string b) {
    if (a == "0" || b == "0") {
        return "0";
    }
    int m = a.size() - 1, n = b.size() - 1, carry = 0;

    string product;

    for (int i = 0; i <= m + n || carry; ++i) {

        for (int j = max(0, i - n); j <= min(i, m); ++j) {
            carry += (a[m - j] - '0') * (b[n - i + j] - '0');
        }
        product += carry % 10 + '0';
        carry /= 10;
    }
    reverse(begin(product), end(product));
    return product;
}