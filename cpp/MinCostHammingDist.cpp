#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
/**
 * Given a binary string s, and 2 integers A and B representing the cost of "01" and "10" respectively, minimize the cost of the given string by rearranging it in any order. After rearranging, find the hamming 
 * distance between the original string and the transformed string and print it. If there are more than 1 arrangement that gives the least cost, find the string which gives the minimum hamming distance.
 * 
 * 1 <= len(s) <= 10^5
 * 0 <= A,B <= 10^4
 * 
*/
using namespace std;

string findDist(string s, int A, int B) {
    int num1 = 0;
    int num0 = 0;
    int result = 0;
    for (size_t i = 0; i < s.length(); i++) {
        if (s[i] == '1') {
            num1++;
        } else if (s[i] == '0') {
            num0++;
        } else {
            return "INVALID";
        }
    }
    if (num0 == 0 || num1 == 0) { // input is either 0000000 or 11111111
        return "0";
    }
    if (A < B) { // transform to 000....111
        int j = 0;
        while (j < num0) {
            if (s[j] != '0') {
                result++;
            }
            j++;
        }
        int i = 0;
        while (i < num1) {
            if (s[j] != '1') {
                result++;
            }
            i++;
            j++;
        }

    } else { // transform to 111.....000
        int j = 0;
        while (j < num1) {
            if (s[j] != '1') {
                result++;
            }
            j++;
        }
        int i = 0;
        while (i < num0) {
            if (s[j] != '0') {
                result++;
            }
            i++;
            j++;
        }
    } 
    return to_string(result);

}

int main() {

    cout << findDist("10101", 3, 3) << endl; // 2
    cout << findDist("000111", 5, 1) << endl; // 6
    cout << findDist("0100", 3, 2) << endl; // 2
    cout << findDist("000", 4, 5) << endl; // 0
    cout << findDist("00001", 5, 1) << endl; // 2
    return 0; 
}