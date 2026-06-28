#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    public:
    Node(int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* reverseDLL(Node* head){   // Reverse a DLL    (Difficult but IMP.)   
// OPTIMAL (Striver): (Iterative => swapping the pointer direction):  ==> Different from "LC_206: Reverse a SLL"
// t = n   s = 1 
    
    if(head == nullptr || head->next == nullptr) return head;

    Node* temp = head;
    Node* prev = nullptr;
    while(temp != nullptr){     // **U** at each iteration, just swap the pointers: ->back , ->next
        prev = temp->back;  // ** thought-process: swap 2 variables: ("prev" acts as a temporary variable)
        temp->back = temp->next;
        temp->next = prev;

        temp = temp->back;  // ***U*** moving forward in original LL
    }
    
    return prev->back;  // *U* prev = second-last node   ==>   So, prev->back = last node
    
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2, nullptr, head);
    head->next->next = new Node(3, nullptr, head->next);
    head->next->next->next = new Node(4, nullptr, head->next->next);
    head->next->next->next->next = new Node(5, nullptr, head->next->next->next);

    head = reverseDLL(head);

    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    
    return 0;
}

// =========
// DIY, {similar to LC_206.cpp}
// my-way (brute GOOD): (add to another LL):  t = n   s = n 
// =========^

// striver (brute): (using stack):  t = 2n = n   s = n  [SAME as brute LC_206]
    // Node* temp = head;
    // stack<int> st;
    // while(temp != nullptr){
    //     st.push(temp->data);
    //     temp = temp->next;
    // }
    // temp = head;
    // while (temp !=  nullptr){
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }

    // return head;