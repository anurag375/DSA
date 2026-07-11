#include<bits/stdc++.h>	//#include<iostream>
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


class Solution {    // 148. Sort List

// OPTIMAL: [modified Merge Sort]:  
// t = (n + n/2) * log n [*U* n/2 to find middle node at each iteration]    ;    s = log n [**U** for recursive stack space]
    ListNode* findMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        fast = fast->next;  // **U** diff from usual [as we need the 1st mid-node in EVEN-sized LL]

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
   
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){ // [copy-pasted from LC_21]
        if(list1 == nullptr) return list2;  // (these are 2 edge cases)
        if(list2 == nullptr) return list1;

        ListNode* t1 = list1;
        ListNode* t2 = list2;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* mover = dummyNode;
        while(t1 != nullptr && t2 != nullptr){
            if(t1->val < t2->val){
                mover->next = t1;
                mover = t1;

                t1 = t1->next;
            }else{
                mover->next = t2;
                mover = t2;

                t2 = t2->next;
            }
        }

        // gathering if anything is left
        if(t1) mover->next = t1;
        if(t2) mover->next = t2;    // or use 'else' here

        return dummyNode->next; // head
    }

public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* mid = findMiddle(head);    // (Tortoise-Hare)
        
        ListNode* leftHead = head;    // *
        ListNode* rightHead = mid->next;  // *

        mid->next = nullptr;    // **U** imp.

        // 1> divide    [*U* returns something => diff. from classic Merge Sort]
        leftHead = sortList(leftHead);
        rightHead = sortList(rightHead);

        // 2> merge     [*U* returns something => diff. from classic Merge Sort]
        head = mergeTwoLists(leftHead,rightHead);

        return head;
    }
};


int main(){
    Solution s;
    ListNode *head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    head = s.sortList(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}


    // BRUTE: [using hash array]   t = (2n + n log n)     s = n
        // vector<int> v;
        // ListNode* temp = head;
        // while(temp){
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }

        // sort(v.begin(), v.end());

        // temp = head;
        // int idx = 0;
        // while(temp){
        //     temp->val = v[idx++];
        //     temp = temp->next;
        // }

        // return head;