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

class Solution {    // 141. Linked List Cycle
public:
    bool hasCycle(ListNode *head) {
    // OPTIMAL: (Tortoise-Hare):    t = around O(n)   s = 1
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != nullptr && fast->next != nullptr){
            // *U* Since both pointers start at head, move them FIRST, then compare.
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        }
        return false;
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = head->next->next;    // *U* 4th node loops with 2nd node

    cout << s.hasCycle(head) << endl;
    return 0;
}


    // BRUTE: striver-way: (little better) 
    // t = n * (2*1) = (n) => unordered map (average case)   +   n*n (worst case)
        // OR  n * (2*log n) = (n log n) => ordered map
    // s = n
        // unordered_map<ListNode*, bool> mp;  // bool = true (MARK FOUND) ; false (NOT..)
        // ListNode* temp = head;

        // while(temp){
        //     if(mp[temp] == 1) return true;
        //     mp[temp] = 1;
        //     temp = temp->next;
        // }
        // return false;



    // BRUTE: my-way: (hash set)  t = n log n  ==> [.find(), .insert() takes log n]     s = n
        // set<ListNode*> st;
        // ListNode* temp = head;

        // while(temp){
        //     if(st.find(temp) != st.end()) return true;
        //     st.insert(temp);
        //     temp = temp->next;
        // }
        // return false;