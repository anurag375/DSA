#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    public:
    ListNode(int data1, ListNode* next1){
        val = data1;
        next = next1;
    }

    public:
    ListNode(int data1){
        val = data1;
        next = nullptr;
    }
};


class Solution {     // 2. Add Two Numbers
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // striver ONLY:   t = max(size1, size2)   s = 1 ; or  max (size1, size2) for storing answer

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        ListNode* dummyHead = new ListNode(-1);   // **U** created a dummy-head of Sum-LL -> Real-head will be just next to the dummy-one
        ListNode* mover = dummyHead;

        int carry = 0;

        while(temp1 != nullptr || temp2 != nullptr){
            int sum = carry;
            if(temp1) sum += temp1->val;    // same as (temp1 != nullptr)
            if(temp2) sum += temp2->val;

            ListNode* newNode = new ListNode(sum % 10);    // *U* unit's value
            mover->next = newNode;
            mover = newNode;

            carry = sum / 10;   // *U* carry for next iteration

            if(temp1) temp1 = temp1->next;
            if(temp2) temp2 = temp2->next;
        }

        if(carry != 0){     // *U* if carry is still left after the last iteration
            ListNode* node = new ListNode(carry);
            mover->next = node;
        }
        
        return dummyHead->next;
    }
};


int main(){
    ListNode* l1 = new ListNode(2); // int = 342
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    ListNode* l2 = new ListNode(5); // int = 465
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;
    ListNode* sumList = s.addTwoNumbers(l1, l2);    // int = 807 => reverse LL = 7 0 8
    while(sumList != nullptr){
        cout << sumList->val << " ";
        sumList = sumList->next;
    }
    return 0;
}


    // RETRY:
        // ListNode* temp1 = l1;
        // ListNode* temp2 = l2;
        // ListNode* sumList = new ListNode(-1);   // **U** created a dummy-head -> Real-head will be just next to the dummy-one
        // ListNode* mover = sumList;

        // int carry = 0;
        // int sum = 0;

        // while(temp1 != nullptr || temp2 != nullptr){
        //     sum = carry;
        //     if(temp1 != nullptr && temp2 != nullptr) sum = sum + temp1->val + temp2->val;
        //     else if(temp1 != nullptr) sum = sum + temp1->val;
        //     else if(temp2 != nullptr) sum = sum + temp2->val;

        //     ListNode* node = new ListNode(sum % 10);    // *U* 
        //     mover->next = node;
        //     mover = node;

        //     carry = sum / 10;   // *U* 

        //     if(temp1 != nullptr) temp1 = temp1->next;
        //     if(temp2 != nullptr) temp2 = temp2->next;
        // }

        // if(carry != 0){  // *U* 
        //     ListNode* node = new ListNode(carry);
        //     mover->next = node;
        // }
        // return sumList->next;