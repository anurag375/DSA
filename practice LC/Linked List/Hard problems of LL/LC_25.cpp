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

class Solution {    // 25. Reverse Nodes in k-Group
    // optimal: t = n   s = 1
    
    ListNode* findKthNode(ListNode* head, int k){
        ListNode* temp = head;
        while(temp){
            k--;
            if(k == 0) return temp;
            temp = temp->next;
        }
        return nullptr; // LL ended
    }

    ListNode* reverse(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = nullptr;
        
        while(temp){
            ListNode* front = temp->next;
            temp->next = prev;

            prev = temp;
            temp = front;
        }
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* revPrevSectionTail = nullptr;    // must be initialized

        while(temp){
            ListNode* kthNode = findKthNode(temp, k);   // *U* don't write 'head'
            
            if(kthNode == nullptr){
                if(revPrevSectionTail) revPrevSectionTail->next = temp; // *U*
                break;
            }
            // else:
            ListNode* markNextSectionNode = kthNode->next;
            kthNode->next = nullptr;
            ListNode* revSectionHead = reverse(temp);   // *U* don't write 'head'

            if(temp == head) head = kthNode;
            else{
                revPrevSectionTail->next = revSectionHead;
            }

            revPrevSectionTail = temp;
            temp = markNextSectionNode;
        }

        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    int k =  3;

    Solution s;
    head = s.reverseKGroup(head, k);
    while(head){
        cout << head->val << " ";
        head = head->next;
    }
    return 0;
}