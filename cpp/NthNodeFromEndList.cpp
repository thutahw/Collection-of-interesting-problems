#include<iostream>
#include<vector>
/**
 * Remove nth Node from the end of the list. 2 pointers approach.
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *slow=head,*fast=head;
        while(n > 0){
            fast=fast->next;
            n--;
        }
        if(fast==NULL){
            return slow->next;
        
        }
        while(fast->next != NULL){  // iterate for this # of nodes until you reach the node to be removed
            slow=slow->next;
            fast=fast->next;
        }
        slow->next = slow->next->next;
        return head;
}

int main() {
    return 0;
}