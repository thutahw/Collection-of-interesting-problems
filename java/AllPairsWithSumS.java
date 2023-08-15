/*
 * Given a list of unique integers, find all pairs of integers with their sum equivalent to S
 * O(n)
 */

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class AllPairsWithSumS {

    static ArrayList<ArrayList<Integer>> findAllPairs(int[] a, int S) {
        Map<Integer, Integer> hmap = new HashMap<>();
        ArrayList<ArrayList<Integer>> lst = new ArrayList<>();
        for (int j : a) {
            if (!hmap.containsKey(j)) {
                hmap.put(S - j, j);
            } else {
                ArrayList<Integer> temp = new ArrayList<>();
                temp.add(hmap.get(j));
                temp.add(j);
                lst.add(temp);
            }
        }
        return lst;
    }
    public static void main(String[] args) {
        int[] arr = new int[]{5,4,-3,1,2,9};
        int S = 6;
        ArrayList<ArrayList<Integer>> lst = findAllPairs(arr, S);
        for (ArrayList<Integer> alst : lst) {
            System.out.println(" " + alst.get(0) + " " + alst.get(1));
        }
    }

}
