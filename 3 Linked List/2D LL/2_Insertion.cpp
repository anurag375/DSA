// 8 types: (before + after) separately
    // 1.1. at head, 
    // 1.2. at tail, 
    // 1.3. at position       // ***** assume, 1 <= k <= n
    // 1.4. before a value    // ***** assume, valNode != head

// for "after" , DO IT YOURSELF --> similar to "before" (just change the pointers accordingly)

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

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ========= extra ======== ^

// 1.1
Node* insertBeforeHead(Node* head, int val){
    Node* newHead = new Node(val, head, nullptr);
    head->back = newHead;
    return newHead;
}

// 1.2
Node* insertBeforeTail(Node* head, int val){
    Node* tail = head;

    if(head->next == nullptr){ // <1> for length = 1
        return insertBeforeHead(head, val);
    }

    while(tail->next != nullptr){   // <2> for length > 1
        tail = tail->next;
    }
    Node* prev = tail->back;
    Node* newNode = new Node(val, tail, prev);

    prev->next = newNode;
    tail->back = newNode;
    return head;
}

// 1.3  
Node* insertBeforePosition(Node* head, int val, int k){  // **** assume, 1 <= k <= n
// (striver way)
    // if(k == 1){
    //     return insertBeforeHead(head, val);
    // }

    // Node* temp = head;
    // int cnt = 0;
    // while (temp != nullptr){
    //     cnt++;
    //     if(cnt == k) break;
    //     temp = temp->next;
    // }
    // Node* prev = temp->back;
    // Node* newNode = new Node(val, temp, prev);
    // prev->next = newNode;
    // temp->back = newNode;
    // return head;
    

// (my-way, BUT similar to 3_deletion.cpp from striver)
    int cnt = 0;
    Node* temp = head;
    while(temp != nullptr){
        cnt++;
        if(cnt == k) break;
        temp = temp->next;
    }

    if(temp->back == nullptr){
        return insertBeforeHead(head, val);
    }
    else if(temp->next == nullptr){
        return insertBeforeTail(head, val);
    }
    else{
        Node* prev = temp->back;
        Node* newNode = new Node(val, temp, prev);

        prev->next = newNode;
        temp->back = newNode;
        return head;
    }
}

// 1.4
void insertBeforeValue(Node* valNode, int val){
    Node* prev = valNode->back;
    Node* newNode = new Node(val, valNode, prev);

    prev->next = newNode;
    valNode->back = newNode;
}


int main(){
    Node* head = new Node(4);
    head->next = new Node(5, nullptr, head);
    head->next->next = new Node(1, nullptr, head->next);
    head->next->next->next = new Node(9, nullptr, head->next->next);

    print(head);

    head = insertBeforeHead(head, 6);
    print(head);

    head = insertBeforeTail(head, 7);
    print(head);

    head = insertBeforePosition(head, 3, 2);    // position = 2
    print(head);

    insertBeforeValue(head->next->next, 2);
    print(head);
    return 0;
}