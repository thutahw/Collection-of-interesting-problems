/*
 Regex handling.

 input: (25, 4) (1, -6)
 output: 26
*/
import java.util.Scanner;

public class DistanceBetweenPoints {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        String s1 = sc.next().replaceAll("[^0-9.-]", "");
//        String s2 = sc.next().replaceAll("[^0-9.-]", "");
//        String s3 = sc.next().replaceAll("[^0-9.-]", "");
//        String s4 = sc.next().replaceAll("[^0-9.-]", "");
        String a = sc.next();
        String b = sc.next();
        String c = sc.next();
        String d = sc.next();
        String s1 = "";
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) == '(' || a.charAt(i) == ',') {
                continue;
            }
            s1 += a.charAt(i);
        }
        String s2 = "";
        for (int i = 0; i < b.length(); i++) {
            if (b.charAt(i) == ')') {
                continue;
            }
            s2 += b.charAt(i);
        }
        String s3 = "";
        for (int i = 0; i < c.length(); i++) {
            if (c.charAt(i) == '(' || c.charAt(i) == ',') {
                continue;
            }
            s3 += c.charAt(i);
        }
        String s4 = "";
        for (int i = 0; i < d.length(); i++) {
            if (d.charAt(i) == ')') {
                continue;
            }
            s4 += d.charAt(i);
        }
        sc.close();
        int x1 = Integer.parseInt(s1);
        int y1 = Integer.parseInt(s2);
        int x2 = Integer.parseInt(s3);
        int y2 = Integer.parseInt(s4);
        double ans  = Math.sqrt( Math.pow(x2-x1,2) +  Math.pow(y2-y1,2));
        System.out.println((int) ans);
    }
}
