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


class Solution {    // 328. Odd Even Linked List   ==> (based on indices;  not values stored)
public:
    ListNode* oddEvenList(ListNode* head) {
    // OPTIMAL: t = n/2 * 2 = n  (**U** because you are doing 2 operations inside an O(n/2) loop)
    // s = 1
        if(head == nullptr || head->next == nullptr) return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;  // memoize/remember this node..
        
        // 1> connect odd & even indices separately:
        while(even != nullptr && even->next != nullptr){    // **U** ONLY check for even (because it is always infront of odd)
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;    // *U* moved 2 nodes
            even = even->next;  // *U* 
        }

        odd->next = evenHead;   // 2> connect odd's end with even's start

        return head;
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
    
    head = s.oddEvenList(head);
    // print LL,
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}


    // BRUTE: (data replacement): t = 2n = n    s = n
        // if(head == nullptr || head->next == nullptr) return head;

        // vector<int> lst;    // this stores numbers in the exact order (Odd->Evens)
        
        // // for Odd indices ==> O(n/2):
        // ListNode* temp = head;  
        // while(temp != nullptr && temp->next != nullptr){
        //     lst.push_back(temp->val);
        //     temp = temp->next->next;    // see
        // }
        // if(temp) lst.push_back(temp->val);  // **U** runs if the last node was skipped above 
        
        // // for Even indices ==> O(n/2):
        // temp = head->next;  
        // while(temp != nullptr && temp->next != nullptr){
        //     lst.push_back(temp->val);
        //     temp = temp->next->next;    // see
        // }
        // if(temp) lst.push_back(temp->val);  // **U** {same}

        // // data replacement:
        // int idx = 0;
        // temp = head;
        // while(temp != nullptr){
        //     temp->val = lst[idx++];
        //     temp = temp->next;
        // }

        // return head;