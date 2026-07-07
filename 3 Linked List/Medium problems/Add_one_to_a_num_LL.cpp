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

class Solution{     // Add one to a number represented by LL    ==> [its BRUTE is just a little diff. from LC_2]

// OPTIMAL:(using recursion): t = n      s = n  [because of recursive stack space]
    int helper(ListNode* head){  // *U* (Recursive func)
        
        if(head == nullptr) return 1;   // base case..

        int carry = helper(head->next);
        head->val = head->val + carry;  // **U** {the val can ONLY be <= 10}

        if(head->val < 10){
            return 0;   // {keep everything as it is..}
        }
        
        head->val = 0;  // else (val == 10) ==> *U* needs a new carry
        return 1;
    }

public:
    ListNode* addOne(ListNode* head) {  // *U* (this func. handles only the leftmost carry case: 9 9 9)
        // if(head == nullptr || head->next == nullptr) return head;

        int carry = helper(head);
        if(carry == 1){
            ListNode* newHead = new ListNode(1);
            newHead->next = head;
            return newHead;
        }

        return head;

    }
};

int main(){
    Solution s;
    ListNode *head = new ListNode(9);
    head->next = new ListNode(9);
    head->next->next = new ListNode(9);

    head = s.addOne(head);
    // print LL,
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}


// BRUTE: (using LL reversal): t = (n + n + n) = 3n      s = O(1)

    // ListNode* reverse(ListNode* head){  // [LC_206]
    //     ListNode* temp = head;
    //     ListNode* prev = nullptr;
    //     while(temp){
    //         ListNode* front = temp->next;
    //         temp->next = prev;
    //         prev = temp;
    //         temp = front;
    //     }

    //     return prev;
    // }

    // public:
    // ListNode* addOne(ListNode* head) {
    // // OPTIMAL:
    //     if(head == nullptr || head->next == nullptr) return head;

    //     ListNode* revHead = reverse(head);
    //     ListNode* temp = revHead;

    //     int sum = 0;    // *U* for each digit
    //     int carry = 1;  // *U* let's add the given '1' as carry
    //     while(temp != nullptr){     // [little diff. from LC_2]
    //         sum = carry;
    //         sum += temp->val;
            
    //         temp->val = (sum % 10);
    //         carry = sum / 10;
    //         if(carry == 0) break;   // *U* early break (NO change of nodes afterwards) 

    //         temp = temp->next;
    //     }

    //     ListNode* newHead = reverse(revHead);

    //     if(carry){  // *U* if any carry is still left   (handles case: 9 9 9 + 1)
    //         ListNode* preHead = new ListNode(carry);
    //         preHead->next = newHead;
    //         return preHead;
    //     }

    //     return newHead;
    // }
