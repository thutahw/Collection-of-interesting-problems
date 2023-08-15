
import java.util.Scanner;
import java.util.Stack;

public class cutcopypaste {
    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in);
        String S = sc.nextLine();
        char[] chArr = S.toCharArray();
        int C = sc.nextInt();
        Stack<String> stack = new Stack<>();
        for (int i = 0; i < C; i++) {
            String command = sc.next();
            if (command.equals("COPY")) {
                int start = sc.nextInt();
                int end = sc.nextInt();
                String copied = S.substring(start-1, end);
                System.out.println("copy" + copied);
                stack.push(copied);

            } else if (command.equals("CUT")) {
                int start = sc.nextInt();
                int end = sc.nextInt();
                String copied = S.substring(start-1, end);
                stack.push(copied);
                String temp = "";
                for (int j = 0; j < S.length(); j++) {
                    if (j >= start - 1 && j <= end - 1) {
                        continue;
                    }
                    temp += S.charAt(j);
                }
                System.out.println("cut" + copied);
                S = temp;
            } else {
                int position = sc.nextInt();
                String ss;
                if (stack.size() > 1) {
                    ss = stack.pop();
                } else {
                    ss = stack.peek();
                }
                String temp = "";
                int a = 0;
                int j = 0;
                while (a <= S.length()) {
                    if (a == position-1) {
                        for (int k = 0; k < ss.length(); k++) {
                            temp += ss.charAt(k);
                        }
                        a++;
                    } else {
                        temp += S.charAt(j);
                        j++;
                        a++;
                    }
                }
                S = temp;
            }
        }
        System.out.println(S);
    }
}
