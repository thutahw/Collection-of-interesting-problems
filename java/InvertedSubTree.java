/**
 * A tree is defined to be an inversion of another tree if either:

Both trees are null
Its left and right children are optionally swapped and its left and right subtrees are inversions.
Given binary trees source and target, return whether there's some inversion T of source such that it's a subtree of target. 
That is, whether there's a node in target that is identically same in values and structure as T including all of its descendants.

Constraints

n ≤ 12 where n is the number of nodes in target

Example 1

Input

source = [0, [1, null, [3, null, null]], [2, null, null]]

target = [5, [2, null, null], [0, [2, null, null], [1, [3, null, null], null]]]

Output

True
 */

 public class InvertedSubTree {

    static class Tree {

        int val;
        Tree left;
        Tree right;

        public Tree(int val, Tree left, Tree right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }


    static boolean solve(Tree source, Tree target) {
        if (target == null) {
            return source == target;
        }
        return isInv(source, target) || solve(source, target.left) || solve(source, target.right);
    }

    static boolean isInv(Tree s, Tree t) {
        if (s == null || t == null) {
            return s == t;
        }
        if (s.val != t.val) {
            return false;
        }
        return isInv(s.left, t.right) && isInv(s.right, t.left)
            || isInv(s.left, t.left) && isInv(s.right, t.right);
    }
    public static void main(String[] args) {

        Tree source = new Tree(
                    0, 
                    new Tree(1, 
                            null, 
                            new Tree(3, 
                                    null, 
                                    null)), 
                    new Tree(2, null, null));
        Tree target = new Tree(
                    5,
                    new Tree(2, 
                                null,
                                null),
                    new Tree(0, 
                            new Tree(2,
                                    null,
                                    null),
                            new Tree(1,
                                    new Tree(3,
                                            null,
                                            null),
                                            
                                    null)));

        System.out.println(solve(source,target));
    }

 }