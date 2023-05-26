
import java.util.Arrays;

/**
 * You are given a list of non-negative integers nums. If there are exactly k numbers in nums that are greater than or equal to k, return k. Otherwise, return -1.
 * Constraints 1 ≤ n ≤ 100,000 where n is the length of nums
 *
 * Example 1 Input nums = [5, 3, 0, 9]
 * Output 3
 * Explanation There are exactly 3 numbers that's greater than or equal to 3: [5, 3, 9].
 *
 * O(nlogn)
 */
public class KNumbersGEtoK {

    public static void main (String[] args) {
        int[] arr1 = new int[] {5,3,0,9}; // 3
        int[] arr2 = new int[] {4,4,4,4,4};  // -1
        int[] arr3 = new int[] {1,4,4,4,4}; // 4
        int[] arr4 = new int[] {5,5,5,5,5}; // 5
        int[] arr5 = new int[] {0,1,2,2}; // 2
        System.out.println(solution(arr5));

    }

    static int solution(int[] arr) {
        Arrays.sort(arr);
        for (int i = 0; i < arr.length; i++) {
            if (arr.length - i == arr[i]) {
                if (i > 0 ) {
                    if (arr[i - 1] != arr[i]) {
                        return arr[i];
                    }
                } else {
                    return arr[i];
                }
            }
        }
        return -1;
    }

}
