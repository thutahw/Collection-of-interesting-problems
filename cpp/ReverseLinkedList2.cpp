#include<iostream>
#include<vector>
/**
 * Given the head of a singly linked list and two integers left and right where left <= right, 
 * reverse the nodes of the list from position left to position right, and return the reversed list.
 * 
 * O(n)
*/

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (left == right) {
        return head;
    }

    ListNode* temp = new ListNode(-1); // a dummy node
    ListNode* prev = temp; // previous will always point to the node before "left"
    temp->next = head;

    for(int i = 0; i < left - 1; i++) {
        prev = prev->next;
    }

    ListNode*cur = prev->next; // will keep track of the original node at "left" position

    for(int i = 0; i < right - left; i++) {
       ListNode *ptr = prev->next; //temp node for "left" position's value
       cur->next = cur->next->next;
       prev->next->next = ptr;
    }

    return temp->next; // a modified list
}

int main() {
    return 0;
}