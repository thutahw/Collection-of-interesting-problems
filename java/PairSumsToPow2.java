/**
 * You are given a list of integers nums (can have duplicates). Return the number of pairs i < j such that nums[i] + nums[j] is equal to 2 ** k for some 0 ≤ k.

Constraints

0 ≤ n ≤ 100,000 where n is the length of nums

Example 1

Input

nums = [1, 1, 3, 5]

Output

4

Explanation

We can have the following pairs that sums to power of 2



(1, 1)

(1, 3)

(1, 3)

(3, 5)

O(n)
 */

import java.util.*;
import java.lang.*;

public class PairSumsToPow2 {
    static int solve(int[] nums) {
        ArrayList<Integer> powers = new ArrayList<>();
        long two = 1;
        while (two < Integer.MAX_VALUE) {
            powers.add((int) (two));
            two *= 2;
        }
        HashMap<Integer, Integer> hm = new HashMap<>(); // map complenent to the count
        int n = nums.length;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int currentNum = nums[i];
            for (int j : powers) {
                ans += hm.getOrDefault(j - currentNum, 0);
            }
            hm.put(currentNum, hm.getOrDefault(currentNum,0) + 1); // if the number does not exist in the hashmap, add it to hm with value 1. else, increment current value
        }
        return ans;
    }
    public static void main(String[] args) {

        int[] nums = new int[] {1, 1, 3, 5};
        System.out.println(solve(nums));
    } 
}