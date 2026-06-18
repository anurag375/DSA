
// 4 types:
    // 1. at head, 
    // 2. at tail, 
    // 3. at position
    // 4. befoer a value

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

void print(Node* head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// ======== extra ======== ^

// 1.
Node* atHead(Node* head, int num){
    Node* newHead = new Node(num, head);
    return newHead;
}

// 2.
Node* atTail(Node* head, int num){
    if(head == nullptr) 
        return new Node(num);

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    Node* newTail = new Node(num);
    temp->next = newTail;

    return head;
}

// 3.
Node* atPostion(Node* head, int k, int num){
    if(head == nullptr) {
        if(k == 1) return new Node(num);
        else return head;    // insertion NOT possible
    }

        // striver-way: WITHOUT using 'prev' 
    int cnt = 0;
    Node* temp = head;

    while(temp != nullptr){
        cnt++;
        if(cnt == k-1){
            Node* newEntry = new Node(num, temp->next);
            temp->next = newEntry;
            break;
        }
        temp = temp->next;
    }

    return head;
        
        // my-way: using 'prev' 
    // int cnt = 0;
    // Node* temp = head;
    // Node* prev = NULL;

    // while(temp != nullptr){
    //     cnt++;
    //     if(cnt == k){
    //         Node* newEntry = new Node(num, temp);
    //         prev->next = newEntry;
    //         break;
    //     }
    //     prev = temp;
    //     temp = temp->next;
    // }

    // return head;
}

// 4.
Node* insertBeforeValue(Node* head, int num, int val){  // VERY similar to 3.
    if(head == nullptr) return head;

    if(head->data == val){  // this part is SAME as 1.
        return new Node(num, head);
    }

    bool found = false;  // (OPTIONAL)
    Node* temp = head;
    while(temp->next != nullptr){
        if(temp->next->data == val){
            Node* newEntry = new Node(num, temp->next);
            temp->next = newEntry; 
            found = true;   // (OPTIONAL)
            break;
        }
        temp = temp->next;
    }
    if(!found) cout << "Value NOT found." << endl;  // (OPTIONAL)
    
    return head;
}


int main(){
    Node* head = new Node(4);
    head->next = new Node(5);
    head->next->next = new Node(1);
    head->next->next->next = new Node(9);

    print(head);
    
    // head = atHead(head, 6);
    // or
    head = new Node(6, head);   // ***
    print(head);

    head = atTail(head, 7);
    print(head);

    head = atPostion(head, 3, 8);
    print(head);

    head = insertBeforeValue(head, 2, 8);
    print(head);

    return 0;
}