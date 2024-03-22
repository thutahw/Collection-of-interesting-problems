/**
 * You are given a two-dimensional list of integers matrix containing 1s and 0s. Return the number of elements in matrix such that:

matrix[r][c] = 1
matrix[r][j] = 0 for every j ≠ c and matrix[i][c] = 0 for every i ≠ r
Constraints

0 ≤ n, m ≤ 250 where n and m are the number of rows and columns in matrix

Example 1

Input

matrix = [
    [0, 0, 1],
    [1, 0, 0],
    [0, 1, 0]
]

Output

3

Explanation

We have matrix[0][2], matrix[1][0] and matrix[2][1] meet the criteria.

Example 2

Input

matrix = [
    [0, 0, 1],
    [1, 0, 0],
    [1, 0, 0]
]

Output

1

Explanation

Only matrix[0][2] meet the criteria. The other two 1s share the same column.
 */

import java.util.*;
import java.lang.*;

public class LargestElemInRandC {

    static int solve(int[][] matrix) {
        int count = 0;
        int count2 = 0;
        int ans = 0;
        int index = 0;
        // edge case
        if (matrix.length == 1) {
            int c = 0;
            for (int i = 0; i < matrix[0].length; i++)
                if (matrix[0][i] == 1)
                    c++;
            if (c == 1)
                return 1;
            else
                return 0;
        }
        
        for (int i = 0; i < matrix.length; i++) {
            count = 0;
            count2 = 0;
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 1) {
                    count++;
                    index = j;  // remember that column
                }
            }

            if (count != 1)
                continue;
            for (int k = 0; k < matrix.length; k++)   // check all the rows but fix the column
                if (matrix[k][index] == 1)
                    count2++;
            if (count == 1 && count2 == 1)
                ans++;
        }
        return ans;
    
    }

    public static void main(String[] args) {

        int[][] arr = new int[][] {
                            {1, 0, 1},
                            {0, 1, 0},
                            {0, 0, 1}};
        System.out.println(solve(arr));

    }

}
