#include <bits/stdc++.h> //#include<iostream>
using namespace std;

class ListNode{
public:
    int val;
    ListNode *next;

public:
    ListNode(int data1, ListNode *next1){
        val = data1;
        next = next1;
    }

public:
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};

class Solution{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n){
    // OPTIMAL: (tortoise & hare algo.)     t = O(size)    s = O(1)
        ListNode* slow = head;  // *U* slow will point to the node before the one we want to remove
        
        ListNode* fast = head;
        for(int i=1; i<=n; i++){ // *U* n, because we want to stop at the 'slow' node before the one we want to remove
            fast = fast->next;
        }

        if (fast == nullptr){ // => Edge case: remove head
            ListNode *newHead = head->next;
            delete head;
            return newHead;
        }

     
        while(fast->next != nullptr){ // *U* stop at the last node
            fast = fast->next;
            slow = slow->next;
        }

        // remove:
        ListNode *delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        
        return head;
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = s.removeNthFromEnd(head, 2);
    // print LL,
    while (head){
        cout << head->val << " ";
        head = head->next;
    }

    return 0;
}


    // BRUTE: t = size + (size - n) = O(2 * size)     s = 1
        // ListNode *temp = head;
        // int size = 0;
        // while (temp){
        //     size++;
        //     temp = temp->next;
        // }

        // if (size == n){ // remove head => (Edge case)
        //     ListNode *newHead = head->next;
        //     delete head;
        //     return newHead;
        // }

        // int preRemovePos = size - n; // counted from left->right
        // // int removePos = preRemovePos + 1;

        // int cnt = 1; // *U* should start from 1     ===> my-way (easier)
        // temp = head;
        // while (cnt < preRemovePos){
        //     cnt++;
        //     temp = temp->next;
        // }

        // // while(temp){             ===> striver-way
        // //     preRemovePos--;
        // //     if (preRemovePos == 0) break;
        // //     temp = temp->next;
        // // }

        // // remove:
        // ListNode *delNode = temp->next;
        // temp->next = temp->next->next;
        // delete delNode;

        // return head;




    // RETRY:
        // ListNode* temp = head;
        // int size = 0;
        // while(temp){
        //     size++;
        //     temp = temp->next;
        // }

        // if(size == 1 && n) return nullptr;

        // int preRemovePos = size - n;   // counted from left->right
        // int removePos = preRemovePos + 1;

        // if(removePos == 1){ // remove head => (Edge case)
        //     temp = head;
        //     head = head->next;
        //     delete temp;
        //     return head;
        // }

        // int cnt = 1;    // *U* should start from 1
        // temp = head;
        // while(cnt < preRemovePos){
        //     cnt++;
        //     temp = temp->next;
        // }
        // // remove temp->next:
        // ListNode* delNode = temp->next;   // delNode = node to remove
        // temp->next = temp->next->next;
        // delete delNode;

        // return head;
