#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    public:
    ListNode(int val1, ListNode* next1){
        val = val1;
        next = next1;
    }

    public:
    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};


class Solution {    // 876. Middle of the Linked List
public:
    ListNode* middleNode(ListNode* head) {

    // optimal: (Tortoise-Hare algorithm)    t = n   s = 1
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != NULL && fast->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(){
    Solution s;
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    ListNode* middle = s.middleNode(head);
    cout << middle->val << endl;    // *U* resultant LL starts from (middle + 1) node, so output = (middle + 1) value

    return 0;
}


    // my-way:  t = n   s = n/2
        // int cnt = 0;
        // ListNode* temp = head;
        // while(temp != nullptr){ // 1. find length
        //     cnt++;
        //     temp = temp->next;
        // }

        // int mid = (cnt/2) + 1;  // 2. (LC asks the second middle node , so we do + 1) 

        // temp = head;
        // cnt = 0;
        // while(temp != nullptr){ // 3. final output
        //     cnt++;
        //     if(cnt == mid) return temp;
        //     temp = temp->next;
        // }

        // return nullptr; // placeholder..
