#include<bits/stdc++.h>

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

using namespace std;

struct Tree {
    int val;
    struct Tree* left;
    struct Tree* right;
};

struct Tree* newNode(int data, Tree* left, Tree* right) {
    struct Tree* node = (struct Tree*)malloc(sizeof(struct Tree));
    node->val = data;
    node->left = left;
    node->right = right;
 
    return node;
}

bool recur(Tree* source, Tree* target) {
    if (!source && !target) {
        return true;
    }
    if (!source || !target || source->val != target->val) {
        return false;
    }
    return ((recur(source->left, target->left) && recur(source->right, target->right)) ||
            (recur(source->left, target->right) && recur(source->right, target->left)));
}
bool solve(Tree* source, Tree* target) {
    if (!source && !target) {
        return true;
    }
    if (!source || !target) {
        return false;
    }
    if (source->val == target->val) {
        return (recur(source, target) || solve(source, target->left) ||
                solve(source, target->right));
    } else {
        return (solve(source, target->left) || solve(source, target->right));
    }
}

int main() {
    struct Tree* s_node2 = newNode(2, NULL, NULL);
    struct Tree* s_node3 = newNode(3, NULL, NULL);
    struct Tree* s_node1 = newNode(1, NULL, s_node3);
    
    struct Tree* source = newNode(0, s_node1, s_node2);

    struct Tree* t_node2 = newNode(2, NULL, NULL);
    struct Tree* t_node3 = newNode(3, NULL, NULL);
    struct Tree* t_node2_0 = newNode(2, NULL, NULL);
    struct Tree* t_node1 = newNode(1, t_node3, NULL);
    struct Tree* t_node0 = newNode(0, t_node2_0, t_node1);

    struct Tree* target = newNode(5, t_node2, t_node0);
    
    stringstream ss1;
    ss1 << boolalpha << solve(source, target);
    cout << ss1.str() << endl;
    return 0;

}