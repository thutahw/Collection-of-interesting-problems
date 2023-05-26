/*
 *  A positive integer of n digits is called an Armstrong number of order n (order is the number of digits) if.

    abcd… = pow(a,n) + pow(b,n) + pow(c,n) + pow(d,n) + ….
 */

import java.util.Scanner;

public class ArmStrongNumbers {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = s.length();
        sc.close();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int a = (int) Math.pow(Character.getNumericValue(s.charAt(i)), n);
            sum += a;
        }
        if (sum == Integer.parseInt(s)) {
            System.out.println("True");
        } else {
            System.out.println("False");
        }

    }
}
