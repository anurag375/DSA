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

class Solution {    // 142. Linked List Cycle II


public:
    ListNode *detectCycle(ListNode *head) {
    // OPTIMAL:  t = n       s = 1
        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){   // [*U* 1st collision point]  this block is different from LC_141's OPTIMAL
                slow = head;  // restarts from head..
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;  // ** this time, move fast by 1 step..
                }
                return slow;    // *U* 2nd collision point  ==> answer node
            }
        }

        return nullptr;
    }
};


int main(){
    Solution s;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next;    // *U* 4th node loops with 2nd node

    ListNode* ansNode = s.detectCycle(head);    // start node of loop
    int ans = (ansNode == nullptr) ? -1 : ansNode->val;     // * see

    cout << ans << endl;
    return 0;
}


    // BRUTE:  t = n* (2*1) [2 for operations]       s = n
        // if(head == nullptr || head->next == nullptr) return nullptr;

        // unordered_map<ListNode*, bool> mp;  // bool = true(1) means VISITED | false(0) means NOT visited
        // ListNode* temp = head;

        // while(temp){
        //     if(mp[temp] != 0){
        //         return temp;
        //     }
        
        //     mp[temp] = 1;
        //     temp = temp->next;
        // }

        // return nullptr;