
// 4 types:
    // 1. from head, 
    // 2. from tail, 
    // 3. from position (k),        // ***** assume, 1 <= k <= n
    // 4. via element/value (valNode)   // ***** assume, valNode != head

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

// 1. delete from head:
Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* prev = head;
    head = head->next;
    head->back = nullptr;

    prev->next = nullptr;  // (OPTIONAL for C++)

    delete prev;
    return head;
}

// 2. delete from tail
Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;

    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }

    Node* prev = temp->back;
    prev->next = nullptr;

    temp->back = nullptr;  // (OPTIONAL for C++)

    delete temp;
    return head;
}

// 3. delete from position (k):
Node* deleteFromPosition(Node* head, int k){  // ***** assume, 1 <= k <= n
    if(head == nullptr) return head;

    int cnt = 0;
    Node* kNode = head;
    while(kNode != nullptr){   
        cnt++;
        if(cnt == k) break;

        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    // now check:
    if(prev == nullptr && front == nullptr){    // <1> single element
        delete kNode;
        return NULL;
    }
    else if(prev == nullptr){  // <2> remove head
        return deleteHead(kNode);    // (expand this part)
    }
    else if(front == nullptr){  // <3> remove tail
        return deleteTail(kNode);    // (expand this part)
    }
    else{   // <4> normal deletion
        prev->next = front;
        front->back = prev;

        kNode->back = nullptr;
        kNode->next = nullptr;  // (these 2 are optional in C++)

        delete kNode;
        return head;
    }

    return head;
}

// 4. delete Value (valNode):
void deleteValue(Node* valNode){ // ***** assume, valNode != head
    if(valNode == nullptr) return;

    Node* prev = valNode->back;
    Node* front = valNode->next;

    if(front == nullptr){
        prev->next = nullptr;
        valNode->back = nullptr;   // (optional in C++)
        delete valNode;

        return;
    }
    
    prev->next = front;
    front->back = prev;

    valNode->back = valNode->next = nullptr;    // (optional in C++)
    delete valNode;
    return;

}

int main(){
    Node* head = new Node(4);
    head->next = new Node(5, nullptr, head);
    head->next->next = new Node(1, nullptr, head->next);
    head->next->next->next = new Node(9, nullptr, head->next->next);
    head->next->next->next->next = new Node(7, nullptr, head->next->next->next);
    head->next->next->next->next->next = new Node(2, nullptr, head->next->next->next->next);
    head->next->next->next->next->next->next = new Node(8, nullptr, head->next->next->next->next->next);

    print(head);

    head = deleteHead(head);
    print(head);

    head = deleteTail(head);
    print(head);

    head = deleteFromPosition(head, 3);
    print(head);

    deleteValue(head->next);    // never delete head => will NOT be asked..
    print(head);

    return 0;
}