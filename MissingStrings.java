
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/*
Given 2 strings s and t, print all strings in s in order such that they are not part of the subsequence formed by t.
Algo Idea: Matches the first occurrence of the word in t with the first occurrence of that word in s.
 */

public class MissingStrings {

    static List<String> getMissingStrings(String s, String t) {
        String[] parts = s.split(" ");
        String[] otherparts = t.split(" ");

        List<String> missing = new ArrayList<>();
        int j = 0;
        for (String part : parts) {
            if (j < otherparts.length && part.equals(otherparts[j])) {
                j++;
            } else {
                missing.add(part);
            }
        }

        return missing;


    }

    static void printMissingStrings(List<String> lst) {

        for (String s : lst) {
            System.out.println(s);
        }

    }


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        String t = sc.nextLine();
        List<String> lst = getMissingStrings(s, t);
        printMissingStrings(lst);
    }
}
