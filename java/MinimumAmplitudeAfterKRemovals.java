
import java.util.Arrays;

/**
 * You are given a list of integers nums, and an integer k.
 * Given that you must remove k elements in nums, return the minimum max(nums) - min(nums) value we can achieve.
 *
 * Constraints 1 ≤ n ≤ 100,000 where n is the length of nums k < n
 *
 * Example 1 Input nums = [2, 10, 14, 12, 30] k = 2
 * Output 4
 * Explanation If we remove 2 and 30 then we'd get [10, 14, 12] and 14 - 10 = 4.
 *
 * O(nlogn)
 */
public class MinimumAmplitudeAfterKRemovals {
    public static void main(String[] args) {
        System.out.println(solution(new int[] {2, 10, 14, 12, 30}, 4)); // 0
        System.out.println(solution(new int[] {2, 10, 14, 12, 30}, 3)); // 2
        System.out.println(solution(new int[] {2, 10, 14, 12, 30}, 2)); // 4
        System.out.println(solution(new int[] {2, 10, 14, 12, 30}, 1)); // 12
        System.out.println(solution(new int[] {2, 25, 26, 27, 30}, 1)); // 5
        System.out.println(solution(new int[] {2, 25, 26, 27, 30}, 3)); // 1

    }
    static int solution(int[] arr, int k) {
        if (arr.length <= 1) {
            return 0;
        }
        Arrays.sort(arr);
        int low = 0;
        int high = arr.length - 1;
        int difference = arr[high] - arr[low];

        while (k > 0) {
            if (arr[high-1] - arr[low] <= arr[high] - arr[low+1]) { // remove right
                difference = arr[high-1] - arr[low];
                high--;
            } else {  // remove left
                difference = arr[high] - arr[low+1];
                low++;
            }
            k--;
        }
        return difference;
    }
}
