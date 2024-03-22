/**
 * You are given a lowercase alphabet string s. Return the minimum numbers of contiguous substrings in which s must be broken into such that each substring 
 * is either non-increasing or non-decreasing.

For example, "acccf" is a non-decreasing string, and "bbba" is a non-increasing string.

Constraints

n ≤ 100,000 where n is the length of s

Example 1

Input

s = "abcdcba"

Output

2

Explanation

We can break s into "abcd" + "cba"

Example 2

Input

s = "zzz"

Output

1

Explanation

We can break s into just "zzz"

Example 3

Input

s = "ecab"

Output

2

Explanation

We can break s into "ec" + "ab"  or "eca" + "b"

O(n)
 */

 import java.util.*;
 import java.lang.*;

 public class MonotonousStringGroups {

    static int solve(String s) {
        if (s.length() == 0) {
            return 0;
        }
        int count = 1;
        boolean nonDec = false;
        boolean nonInc = false;
        for (int i = 0; i < s.length(); i++) {
            if (i == 0) {
                continue;
            }
            if (s.charAt(i) > s.charAt(i-1)) {  // non-dec
                if (nonInc) {
                    count++;
                    nonInc = false;
                } 
                nonDec = true;
                
            } else if (s.charAt(i) < s.charAt(i-1)) { // non-inc
                if (nonDec) {
                    count++;
                    nonDec = false;
                } 
                nonInc = true;

            } else {
                continue;
            }
        }

        return count;
    }

    public static void main(String[] args) {

        String s1 = "abcdcba"; // 2
        String s2 = "zzz"; // 1
        String s3 = "ecab"; // 2
        System.out.println(solve(s1));
        System.out.println(solve(s2));
        System.out.println(solve(s3));
    }

 }