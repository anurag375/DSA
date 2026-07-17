#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }

    Node(int x, Node* next1, Node* prev1) {
        data = x;
        next = next1;
        prev = prev1;
    }
};


// GFG: https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1
class Solution {    // Remove duplicates from a sorted DLL
  public:

    Node* removeDuplicates(Node* head) {
    // ONLY optimal (my-way): [two-pointers]:    t = n     s = 1
    // (similar to what we did in arrays)
        Node* left = head;
        Node* right = head->next;

        while(right){
            if(left->data != right->data){
                left->next = right;
                right->prev = left;

                left = right;
                right = right->next;
            }else{  // (left->data == right->data)
                Node* duplicate = right;
                right = right->next;
                delete duplicate;   // MUST do in C++
            }
        }

        // **U** IMP. to remove the rightmost duplicates
        left->next = right; // *U* 'right' is NULL at this point

        return head;
    }
};

int main(){
    Solution s;

    Node* head = new Node(1);   
    head->next = new Node(1, nullptr, head);
    head->next->next = new Node(1, nullptr, head->next);
    head->next->next->next = new Node(2, nullptr, head->next->next);
    head->next->next->next->next = new Node(3, nullptr, head->next->next->next);
    head->next->next->next->next->next = new Node(4, nullptr, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(4, nullptr, head->next->next->next->next->next);

    head = s.removeDuplicates(head);

    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    return 0;
}


// striver's code:  [same logic BUT different code]