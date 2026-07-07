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

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
    // OPTIMAL: (Tortoise-Hare algorithm)    t = n/2   s = 1
        if(head == nullptr || head->next == nullptr) return nullptr;    // handles edge case (length = 1)

        ListNode* fast = head;
        ListNode* slow = head;

        fast = fast->next->next;    // **U** this is diff. from "Finding middle node"
        
        // 1> traverse: "slow" stops at the node JUST previous to mid
        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2> remove mid node
        ListNode* midNode = slow->next;
        slow->next = slow->next->next;
        delete midNode;

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

    head = s.deleteMiddle(head);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}


    // BRUTE:   t = n + n/2 = n     s = 1
        // if(head == nullptr || head->next == nullptr) return nullptr;   // *U* handles edge case (length = 1)
        // ListNode* temp = head;
        // // 1> find LL length
        // int cnt = 0;
        // while(temp){
        //     cnt++;
        //     temp = temp->next;
        // }

        // // 2> calculate mid
        // int mid = cnt / 2;

        // // 3> reach the node just before the mid
        // temp = head;
        // while(temp){
        //     mid--;
        //     if(mid == 0) break; // *U* this stops JUST before mid
        //     temp = temp->next;
        // }

        // // 4> remove mid node
        // ListNode* removeNode = temp->next;
        // temp->next = temp->next->next;
        // delete removeNode;

        // return head;