/*
 Given 2 integers (low and high), find the number of integers like p such that low <= p <= high, and such that p can be represented
 in the form p = (3^x) x (5^y) for x, y >= 0

 e.g.
 input: 1, 15
 output: 5

 Explanation:
 1 = 3^0 x 5^0
 3 = 3^1 x 5^0
 5 = 3^0 x 5^1
 9 = 3^2 x 5^0
 15 = 3^1 x 5^1
*/
import java.util.Scanner;

public class ImperialNumbers {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int low = sc.nextInt();
        int high = sc.nextInt();
        sc.close();
        int count = 0;

        while (low <= high) {
            int tempL = low;

            while (tempL % 5 == 0) {
                tempL = tempL / 5;
            }
            if (tempL == 1) {
                count++;
                low++;
                continue;
            }
            while (tempL % 3 == 0) {
                tempL = tempL / 3;
            }
            if (tempL == 1) {
                count++;
            }
            low++;

        }
        System.out.print(count);
    }

}
