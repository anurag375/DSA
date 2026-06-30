#include<bits/stdc++.h>	//#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    public:
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};


Node* sort(Node* head){
    // OPTIMAL: t = n       s = 1
    if(head == nullptr || head->next == nullptr) return head;

    Node* head0 = new Node(-1);     // 3 dummy-head nodes just prev. of their actual heads (0,1,2)
    Node* head1 = new Node(-1); 
    Node* head2 = new Node(-1); 

    Node* mover0 = head0;
    Node* mover1 = head1;
    Node* mover2 = head2;

    // 1> connect the original LL into 3 ()
    Node* temp = head;
    while(temp != nullptr){
        if(temp->data == 0){
            mover0->next = temp;
            mover0 = temp;
        }
        else if(temp->data == 1){
            mover1->next = temp;
            mover1 = temp;
        }
        else{
            mover2->next = temp;
            mover2 = temp;
        }

        temp = temp->next;
    }

    // ***U***
    mover0->next = (head1->next) ? (head1->next) : (head2->next);
    mover1->next = head2->next;
    mover2->next = nullptr;     // *U* putting nullptr is important.. as the original LL's last node may not be 2
    // * * * *

    Node* newHead = head0->next;

    delete head0;
    delete head1;
    delete head2;
    
    return newHead;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(0);
    head->next->next = new Node(2);
    head->next->next->next = new Node(0);
    head->next->next->next->next = new Node(1);

    head = sort(head);
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    
    return 0;
}


// BRUTE: (using 3 counter variables)   t = 2n      s = 1
    // if(head == nullptr || head->next == nullptr) return head;

    // int cnt0 = 0;
    // int cnt1 = 0;
    // int cnt2 = 0;

    // Node* temp = head;
    // while(temp != nullptr){
    //     if(temp->data == 0) cnt0++;
    //     else if(temp->data == 1) cnt1++;
    //     else cnt2++;

    //     temp = temp->next;
    // }

    // temp = head;
    // while(temp != nullptr){
    //     if(cnt0){
    //         temp->data = 0;
    //         cnt0--;
    //     }
    //     else if(cnt1){
    //         temp->data = 1;
    //         cnt1--;
    //     }
    //     else{
    //         temp->data = 2;
    //         cnt2--;
    //     }

    //     temp = temp->next;
    // }

    // return head;