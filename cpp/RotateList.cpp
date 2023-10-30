#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

 ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
            return head;
        }
        auto iter = head;
        auto len = 1;
        while (iter->next != nullptr) {
            iter = iter->next; 
            ++len;
        }
        // create a ring by closing the list
        iter->next = head;
        iter = head;
        // find one element before the new head
        for (int i = 0; i < len - (k % len) - 1; ++i) {   // optimize using modulo operator to skip having the same sequence
            iter = iter->next;
        }
        head = iter->next;
        // break the ring by opening the list
        iter->next = nullptr;
        return head;
}

int main() {
    return 0;
}