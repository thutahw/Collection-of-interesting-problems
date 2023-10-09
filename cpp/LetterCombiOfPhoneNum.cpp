#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

/**
 * Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons). Note that 1 does not map to any letters.

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].

Time Complexity : O(3^N × 4^M) where N is the number of digits which have 3 letters assigned to it and M is the number of digits which has 4 letters assigned to it.

*/

using namespace std;

vector<string> letterCombinations(string digits) {
    if(digits.empty()) {
        return {};
    }
    vector<string> pad = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};  // 0-9
    vector<string> result;
    result.push_back("");
    for(auto key : digits) {
        vector<string> temp;
        for(auto candidate : pad[key-'0']) {
            for(auto c : result) {
                temp.push_back(c + candidate);
            }
        }
        result.clear();
        result = temp;
    }
    return result;   
}

