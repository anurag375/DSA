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

class Solution {    // 61. Rotate List
public:
    ListNode* rotateRight(ListNode* head, int k) {
    // optimal ONLY:    t = 2n = n      s = 1
        if(k == 0 || head == nullptr) return head;

        ListNode* temp = head;
        ListNode* markTail;
        int size = 0;
        while(temp){
            size++;
            markTail = temp;
            temp = temp->next;
        }

        if(k % size == 0) return head;

        int cntK = k % size;   // reducing the rotations
        cntK = size - cntK;    // *U* make 'cntK' MOVE from left->right

        temp = head;    // *U* re-position
        while(temp){
            cntK--;
            if(cntK == 0){
                ListNode* newHead = temp->next;
                temp->next = nullptr;
                markTail->next = head;

                return newHead;
            }

            temp = temp->next;
        }

        return head; // dummy return (won't actually return);
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k = 2;

    Solution s;
    head = s.rotateRight(head, k);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}