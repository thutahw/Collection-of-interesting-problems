
/**
 * Given positive integers start and end (start < end), return the MINIMUM number of operations needed to convert start to end
 * using these operations:
 * Increment by 1
 * Multiply by 2
 *
 * Constraints start < end < 2 ** 31
 *
 * Example 1 : Multiplication first dominates
 * Input start = 2 end = 9
 * Output 3
 * Explanation We can multiply 2 to get 4, and then again to get 8, then add 1 to get 9.
 *
 * Example 2: Addition first dominates
 * input: 6, 16
 * output: 3
 * Explanation: 6->7->8->16
 *
 * Approach: recursive solution, might TLE.
 */

public class TargetNumWithOperations {

    public static void main(String[] args) {
        System.out.println(solution(3, (int)Math.pow(2, 31) - 1));

    }

    // TLE solution
//    static int solution(int a, int b){
//        if (a > b) {
//            return Integer.MAX_VALUE;
//        } else if (b == a + 1 || b == a * 2) {
//            return 1;
//        } else {
//            return 1 + Math.min(solution(a * 2, b), solution(a + 1, b));
//        }
//    }
    static int solution(int start, int end) {
        int ops = 0;
        while (end / 2 >= start) {
            ops += 1 + (end % 2);
            end /= 2;
        }
        return ops + end - start;
    }


}
