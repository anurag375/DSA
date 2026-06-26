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

Node*

int main(){
    Node* head = new Node(4);
    head->next = new Node(5, nullptr, head);
    head->next->next = new Node(1, nullptr, head->next);
    head->next->next->next = new Node(9, nullptr, head->next->next);


    return 0;
}