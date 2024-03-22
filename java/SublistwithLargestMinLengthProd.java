/**
Problem Statement :

You are given a list of integers nums and an integer pos. Find a sublist A of nums that includes the index (0-indexed) pos such that min(A) * A.length is maximized and return the value.

Constraints

n ≤ 100,000 where n is the length of nums

Example 1

Input

nums = [-1, 1, 4, 3]

pos = 3

Output

6

Explanation

The best sublist is [4, 3]. Since min(4, 3) = 3 and its length is 2 we have 3 * 2 = 6.

*/

import java.util.*;
import java.lang.*;

public class SublistwithLargestMinLengthProd {

    static int NEG = -100000000;
    public int solve(int[] nums, int pos) {
        int l = pos;
        int r = pos;
        int currMin = nums[pos];

        int ret = NEG;

        for (int i = 1; i <= nums.length; i++) {
            ret = Math.max(ret, currMin * i);

            int left = l - 1 >= 0 ? nums[l - 1] : NEG;
            int right = r + 1 < nums.length ? nums[r + 1] : NEG;

            if (left > right) {
                currMin = Math.min(currMin, left);
                l--;
            } else {
                currMin = Math.min(currMin, right);
                r++;
            }
        }
        return ret;
    }
    
}