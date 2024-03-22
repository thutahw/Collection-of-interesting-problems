/**
 * You are given a strictly increasing list of integers nums and a list of integers values, both of the same length. 
Find a pair i ≤ j that maximizes values[i] + values[j] + nums[j] - nums[i] and return the value.

Constraints

2 ≤ n ≤ 100,000 where n is the length of nums and values

Example 1

Input

nums = [0, 1, 6]

values = [-5, 5, 4]

Output

14

Explanation

Here we can pick i = 1 and j = 2 to get 5 + 4 + 6 - 1

Example 2

Input

nums = [0, 3, 6]

values = [-5, 4, 8]

Output

16

Explanation

Here we can pick i = 2 and j = 2 to get 8 + 8 + 6 - 6

O(n^2)

 */

 import java.util.*;
 import java.lang.*;

 public class LargestPairOfPoints {

    static int solve(int[] nums, int[] values) {

        int size = nums.length;
        int value = Integer.MIN_VALUE;
        for (int i = 0; i < size; i++) {
            for (int j = i; j < size; j++) {
                int currentVal = values[i] + values[j] + nums[j] - nums[i];
                value = Math.max(value, currentVal);
            }
        }

        return value;   
    }

    public static void main(String[] args) {

        int[] nums1 = new int[] {0,1,6};
        int[] values1 = new int[] {-5, 5, 4};
        System.out.println(solve(nums1, values1)); //14

        int[] nums2 = new int[] {0, 3, 6};
        int[] values2 = new int[] {-5, 4, 8};
        System.out.println(solve(nums2, values2)); //16
    }
 }


 /*
  * O(n) algorithm

  public int solve(int[] nums, int[] values) {
        int N = nums.length;
        int max = Integer.MIN_VALUE;
        int ans = Integer.MIN_VALUE;
        for (int j = 0; j < N; j++) {
            max = Math.max(max, values[j] - nums[j]);  // To keep track of i
            ans = Math.max(ans, nums[j] + values[j] + max);
        }
        return ans;
    }
  */