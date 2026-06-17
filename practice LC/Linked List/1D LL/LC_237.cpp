#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;

    public:
    ListNode(int val1, ListNode* next1){
        val = val1 ;
        next = next1;
    }

    public:
    ListNode(int val1){
        val = val1;
        next = nullptr;
    }
};


// ======== MAIN ========  
class Solution {    // 237. Delete Node in a Linked List
public:
    void deleteNode(ListNode* node) {
    // my-way (code) + @codestorywithMIK (logic):

        while(node->next->next != nullptr){
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        delete node->next; // optional
        node->next = nullptr;
    }
};
// ======== MAIN ======== ^ 


// ======== extra ======== 
void print(ListNode* temp){
    while(temp != nullptr){    // (temp != nullptr)
        cout << temp->val << " ";
        temp = temp->next;
    }   
    cout << endl;
     
}
// ======== extra ======== ^

int main(){
    Solution sol;
    ListNode* head = new ListNode(4);
    head->next = new ListNode(5);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(9);

    cout << "Before deletion: ";
    print(head);

    sol.deleteNode(head->next);  // Delete node with value 5

    cout << "After deletion: ";
    print(head);

    return 0;
}