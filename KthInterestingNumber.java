
/*
Given a positive integer K, return the Kth interesting number.
A number is interesting if it starts with even digit and alternates between even and odd digits.
[2, 4, 6, 8, 21, 23, 25, 27, 29, 41, 43, 45, 47, 49, 61, 63, 65, 67, 69, 81, 83, 85, 87, 89, 210]
 1  2  3  4  5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25


e.g. K = 3,
[2, 4, 6]
output: 6

e.g. K = 5,
[2, 4, 6, 8, 21]
output: 21
 */

// Idea:  split into each digit and increment 2 (or 4) each time, append 1 or 0 if needed, then convert to long

import java.util.Scanner;

public class KthInterestingNumber {

    static long findKthNumber(int K) {

        int counter = 0;
        long currentNumber = 0L;

        while (counter < K) {

            boolean carry = false;
            StringBuilder finalValue = new StringBuilder();
            String temp = String.valueOf(currentNumber);

            for (int i = temp.length() - 1; i >= 0; i--) {
                int currentDigit = Character.getNumericValue(temp.charAt(i));

                if (i == temp.length() - 1) {
                    if (currentNumber == 8) {
                        currentDigit += 4;
                    } else {
                        currentDigit += 2;
                    }
                    if (currentDigit >= 10) {
                        carry = true;
                    }

                } else if (i == 0) {
                    if (carry) {
                        if (currentDigit == 8) {
                            currentDigit += 4;
                        } else {
                            currentDigit += 2;
                        }
                    }
                    carry = currentDigit >= 10;

                } else if (carry) {
                    currentDigit += 2;
                    if (currentDigit < 10) {
                        carry = false;
                    }
                }

                String value = Integer.toString(currentDigit % 10);
                finalValue.insert(0, value);

            }

            if (carry) {
                char c = finalValue.charAt(finalValue.length()-1);
                if (Character.getNumericValue(c) % 2 == 0) {  //even -> append 1
                    finalValue.append(Integer.toString(1));
                } else {
                    finalValue.append(Integer.toString(0)); // odd -> append 0
                }
            }

            currentNumber = Long.parseLong(finalValue.toString());
            counter++;

        }
        return currentNumber;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int K = sc.nextInt();
        sc.close();

        System.out.println(findKthNumber(K));
    }
}
