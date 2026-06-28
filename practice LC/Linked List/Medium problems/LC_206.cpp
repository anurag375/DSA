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


class Solution {    // Reverse a Linked List
public:

    ListNode* reverseList(ListNode* head) {
    // optimal: (Recursive): (a LITTLE difficult to understand)  t = n   s = 1 
        // if(head == nullptr || head->next == nullptr) return head;

        // ListNode* newHead = reverseList(head->next);
        // ListNode* front = head->next;

        // front->next = head;
        // head->next = nullptr;

        // return newHead;


        ListNode* temp = head;
        ListNode* prev = nullptr;
        ListNode* front = nullptr;   // u can also define "front" inside while loop
        
        while(temp != nullptr){
            front = temp->next;
            temp->next = prev;

            prev = temp;     // 1st.
            temp = front;    // 2nd. (*U* don't write temp->next)
        }

        return prev;    // **U** prev = new head

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
    
    head = s.reverseList(head);
    ListNode* temp = head;
    while (temp != nullptr)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    
    return 0;
}



    // optimal: (Iterative => swapping the pointer direction):  t = n   s = 1 
        // ListNode* temp = head;
        // ListNode* prev = nullptr;
        // ListNode* front = nullptr;   // u can also define "front" inside while loop
        
        // while(temp != nullptr){
        //     front = temp->next;
        //     temp->next = prev;

        //     prev = temp;     // 1st.
        //     temp = front;    // 2nd.
        // }

        // return prev;    // **U** prev = new head



    // my-way (brute GOOD): (add to another LL):  t = n   s = n 
        // ListNode* temp = head;
        // ListNode* revHead = nullptr;
        // ListNode* revNext = nullptr;
        
        // while(temp != nullptr){
        //     revHead = new ListNode(temp->val, revNext);
        //     revNext = revHead;
        //     temp = temp->next;
        // }

        // return revHead;



    // striver (brute): (using stack):  t = 2n = n   s = n 
        // ListNode* temp = head;
        // stack<int> st;
        
        // while(temp != nullptr){
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;
        // while(temp != nullptr){
        //     temp->val = st.top();
        //     st.pop();
        //     temp = temp->next;
        // }

        // return head;