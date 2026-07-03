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

class Solution{     // 234. Palindrome Linked List

// OPTIMAL: t = (n/2 * 2)+(n/2 * 2) = O(2n)      s = O(1)
    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while(temp != nullptr){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;    // *U* new head is "prev", not "head"
    }

public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        // 1> find mid node (pre-mid node in even-length LL)
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != nullptr && fast->next->next != nullptr){ // *U* slightly diff.
            slow = slow->next;
            fast = fast->next->next;
        }

        // 2> reverse second half
        ListNode* rightHead = reverse(slow->next);

        // 3> compare
        // movers:
        ListNode* right = rightHead;
        ListNode* left = head;
        while(right != nullptr){    // *U* right can reach null
            if(left->val != right->val){
                reverse(rightHead);     // * don't change the given data
                return false;
            }
            left = left->next;
            right = right->next;
        }

        reverse(rightHead);     // * {same}
        return true;
    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(1);

    cout << s.isPalindrome(head) << endl;
    return 0;
}


    // BRUTE: (using stack)     t = 2n      s = n
        // stack<int> st;
        // ListNode* temp = head;

        // while(temp != nullptr){ // *U* stop at the last node
        //     st.push(temp->val);
        //     temp = temp->next;
        // }

        // temp = head;
        // while(temp != nullptr){
        //     if(temp->val != st.top()) return false;
        //     st.pop();
        //     temp = temp->next;
        // }
        // return true;




        // 1 2    5 4 3