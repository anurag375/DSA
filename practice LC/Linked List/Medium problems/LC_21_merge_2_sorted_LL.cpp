#include <bits/stdc++.h> //#include<iostream>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

public:
    ListNode(int data1, ListNode *next1)
    {
        val = data1;
        next = next1;
    }

public:
    ListNode(int data1)
    {
        val = data1;
        next = nullptr;
    }
};

class Solution { // 21. Merge Two Sorted Lists
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
    // OPTIMAL: (a concept of the classic Merge Sort)     
    // t = n + m       s = 1 [we just did link-changes]
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
};

int main()
{
    Solution s;

    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);
    // head1->next->next->next = new ListNode(4);
    // head1->next->next->next->next = new ListNode(5);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);

    ListNode* head = s.mergeTwoLists(head1, head2);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}


    // BRUTE: (hash array)
    // t = 2 * (total of n + m) + total * log (total..)      s = 2 * total of (n + m)    [1 for vector, 1 for LL]

        // if(list1 == nullptr) return list2;  // (these are 2 edge cases)
        // if(list2 == nullptr) return list1;

        // ListNode *temp = list1;
        // vector<int> v;

        // // 1> store in vector
        // while (temp){
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }
        // temp = list2;
        // while (temp){
        //     v.push_back(temp->val);
        //     temp = temp->next;
        // }

        // // 2> sort
        // sort(v.begin(), v.end());

        // // 3> convert to LL
        // ListNode* head = new ListNode(v[0]);
        // ListNode* mover = head;
        // for(int i=1; i<v.size(); i++){
        //     ListNode* newNode = new ListNode(v[i]);
        //     mover->next = newNode;
        //     mover = newNode;
        // }
        
        // return head;